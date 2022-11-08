// -*- C++ -*-
// <rtc-template block="description">
/*!
 * @file  testVelocity3DInTest.cpp
 * @brief TimedVelocity3D type test component. (test code)
 *
 */
// </rtc-template>

#include "testVelocity3DInTest.h"

// Module specification
// <rtc-template block="module_spec">
#if RTM_MAJOR_VERSION >= 2
static const char* const testvelocity3din_spec[] =
#else
static const char* testvelocity3din_spec[] =
#endif
  {
    "implementation_id", "testVelocity3DInTest",
    "type_name",         "testVelocity3DInTest",
    "description",       "TimedVelocity3D type test component.",
    "version",           "1.0.0",
    "vendor",            "AIST",
    "category",          "Test",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
testVelocity3DInTest::testVelocity3DInTest(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_inOut("in", m_in)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
testVelocity3DInTest::~testVelocity3DInTest()
{
}



RTC::ReturnCode_t testVelocity3DInTest::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  
  // Set OutPort buffer
  addOutPort("in", m_inOut);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t testVelocity3DInTest::onFinalize()
{
  return RTC::RTC_OK;
}
*/


//RTC::ReturnCode_t testVelocity3DInTest::onStartup(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t testVelocity3DInTest::onShutdown(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t testVelocity3DInTest::onActivated(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t testVelocity3DInTest::onDeactivated(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


RTC::ReturnCode_t testVelocity3DInTest::onExecute(RTC::UniqueId /*ec_id*/)
{
  return RTC::RTC_OK;
}


//RTC::ReturnCode_t testVelocity3DInTest::onAborting(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t testVelocity3DInTest::onError(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t testVelocity3DInTest::onReset(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t testVelocity3DInTest::onStateUpdate(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t testVelocity3DInTest::onRateChanged(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


bool testVelocity3DInTest::runTest()
{
    return true;
}


extern "C"
{
 
  void testVelocity3DInTestInit(RTC::Manager* manager)
  {
    coil::Properties profile(testvelocity3din_spec);
    manager->registerFactory(profile,
                             RTC::Create<testVelocity3DInTest>,
                             RTC::Delete<testVelocity3DInTest>);
  }
  
}
