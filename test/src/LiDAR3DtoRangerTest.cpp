// -*- C++ -*-
/*!
 * @file  LiDAR3DtoRangerTest.cpp
 * @brief LiDAR3d to range translation component
 * @date $Date$
 *
 * $Id$
 */

#include "LiDAR3DtoRangerTest.h"

// Module specification
// <rtc-template block="module_spec">
static const char* lidar3dtoranger_spec[] =
  {
    "implementation_id", "LiDAR3DtoRangerTest",
    "type_name",         "LiDAR3DtoRangerTest",
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
LiDAR3DtoRangerTest::LiDAR3DtoRangerTest(RTC::Manager* manager)
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
LiDAR3DtoRangerTest::~LiDAR3DtoRangerTest()
{
}



RTC::ReturnCode_t LiDAR3DtoRangerTest::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("range2d", m_range2dIn);

  // Set OutPort buffer
  addOutPort("range3d", m_range3dOut);

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
RTC::ReturnCode_t LiDAR3DtoRangerTest::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t LiDAR3DtoRangerTest::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t LiDAR3DtoRangerTest::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t LiDAR3DtoRangerTest::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t LiDAR3DtoRangerTest::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t LiDAR3DtoRangerTest::onExecute(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t LiDAR3DtoRangerTest::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t LiDAR3DtoRangerTest::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t LiDAR3DtoRangerTest::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t LiDAR3DtoRangerTest::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t LiDAR3DtoRangerTest::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{

  void LiDAR3DtoRangerTestInit(RTC::Manager* manager)
  {
    coil::Properties profile(lidar3dtoranger_spec);
    manager->registerFactory(profile,
                             RTC::Create<LiDAR3DtoRangerTest>,
                             RTC::Delete<LiDAR3DtoRangerTest>);
  }

};


