// -*- C++ -*-
/*!
 * @file  LiDAR3DtoRanger.cpp
 * @brief LiDAR3d to range translation component
 * @date $Date$
 *
 * $Id$
 */

#define _USE_MATH_DEFINES
#include <math.h>
#include "LiDAR3DtoRanger.h"

// Module specification
// <rtc-template block="module_spec">
static const char* lidar3dtoranger_spec[] =
  {
    "implementation_id", "LiDAR3DtoRanger",
    "type_name",         "LiDAR3DtoRanger",
    "description",       "LiDAR3d to range translation component",
    "version",           "1.0.0",
    "vendor",            "SUGAR SWEET ROBOTICS",
    "category",          "Sensor",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    // Configuration variables
    "conf.default.debug_level", "0",
    "conf.default.skip_count", "30",
    "conf.default.rotate_invertion", "true",
    "conf.default.selct_vertical_index", "8",

    // Widget
    "conf.__widget__.debug_level", "text",
    "conf.__widget__.skip_count", "text",
    "conf.__widget__.rotate_invertion", "text",
    "conf.__widget__.selct_vertical_index", "text",
    // Constraints

    "conf.__type__.debug_level", "short",
    "conf.__type__.skip_count", "short",
    "conf.__type__.rotate_invertion", "string",
    "conf.__type__.selct_vertical_index", "short",

    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
LiDAR3DtoRanger::LiDAR3DtoRanger(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_range3dIn("range3d", m_range3d),
    m_range2dOut("range2d", m_range2d)

    // </rtc-template>
{
    m_rotate_invertion = "true";
}

/*!
 * @brief destructor
 */
LiDAR3DtoRanger::~LiDAR3DtoRanger()
{
}



RTC::ReturnCode_t LiDAR3DtoRanger::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("range3d", m_range3dIn);

  // Set OutPort buffer
  addOutPort("range2d", m_range2dOut);

  // Set service provider to Ports

  // Set service consumers to Ports

  // Set CORBA Service Ports

  // </rtc-template>

  // <rtc-template block="bind_config">
  // Bind variables and configuration variable
  bindParameter("debug_level", m_debug_level, "0");
  bindParameter("skip_count", m_skip_count, "0");
  bindParameter("rotate_invertion", m_rotate_invertion, "true");
  bindParameter("selct_vertical_index", m_selct_vertical_index, "8");
  // </rtc-template>

  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t LiDAR3DtoRanger::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t LiDAR3DtoRanger::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t LiDAR3DtoRanger::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t LiDAR3DtoRanger::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t LiDAR3DtoRanger::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t LiDAR3DtoRanger::onExecute(RTC::UniqueId ec_id)
{
  const uint64_t skip_count = m_skip_count;
  const bool rotate_invertion = m_rotate_invertion == "true" || m_rotate_invertion == "True" || m_rotate_invertion == "TRUE";
  if (m_range3dIn.isNew()) {
    m_range3dIn.read();

    if ((m_range3d.frames.length() / (skip_count + 1)) != m_range2d.ranges.length()) {
      m_range2d.ranges.length(m_range3d.frames.length() / (skip_count + 1));
      m_range2d.geometry.geometry = m_range3d.geometry;
      m_range2d.config.minAngle = m_range3d.config.minAzimuthAngle;
      m_range2d.config.maxAngle = m_range3d.config.maxAzimuthAngle;
      m_range2d.config.angularRes = m_range3d.config.azimuthAngularRes * (skip_count+1);
      m_range2d.config.minRange = m_range3d.config.minRange;
      m_range2d.config.maxRange = m_range3d.config.maxRange;
      m_range2d.config.rangeRes = m_range3d.config.rangeRes;
      m_range2d.config.frequency = m_range3d.config.frequency;
    }

    auto len_org = m_range3d.frames.length();
    auto len = m_range3d.frames.length() / (skip_count + 1);
    int j = 0;
    for(int i = 0;i < len_org && j < len;i+=(skip_count+1)) {
        if (!rotate_invertion) {
            m_range2d.ranges[j] = m_range3d.frames[i].ranges[m_selct_vertical_index];
        }
        else {
            // 逆回転
            m_range2d.ranges[j] = m_range3d.frames[len_org - 1 - i].ranges[m_selct_vertical_index];
        }
        j++;
    }
    m_range2d.tm.sec = m_range3d.tm.sec;
    m_range2d.tm.nsec = m_range3d.tm.nsec;
    m_range2dOut.write();
  }
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t LiDAR3DtoRanger::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t LiDAR3DtoRanger::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t LiDAR3DtoRanger::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t LiDAR3DtoRanger::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t LiDAR3DtoRanger::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{

  void LiDAR3DtoRangerInit(RTC::Manager* manager)
  {
    coil::Properties profile(lidar3dtoranger_spec);
    manager->registerFactory(profile,
                             RTC::Create<LiDAR3DtoRanger>,
                             RTC::Delete<LiDAR3DtoRanger>);
  }

};


