// -*- C++ -*-
/*!
 * @file  LiDAR3DtoRanger.cpp
 * @brief LiDAR3d to range translation component
 * @date $Date$
 *
 * $Id$
 */

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

    // Widget
    "conf.__widget__.debug_level", "text",
    // Constraints

    "conf.__type__.debug_level", "short",

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


