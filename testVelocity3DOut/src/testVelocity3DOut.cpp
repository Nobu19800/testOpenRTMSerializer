// -*- C++ -*-
// <rtc-template block="description">
/*!
 * @file  testVelocity3DOut.cpp
 * @brief TimedVelocity3D type test component.
 *
 */
// </rtc-template>

#include "testVelocity3DOut.h"

// Module specification
// <rtc-template block="module_spec">
#if RTM_MAJOR_VERSION >= 2
static const char* const testvelocity3dout_spec[] =
#else
static const char* testvelocity3dout_spec[] =
#endif
  {
    "implementation_id", "testVelocity3DOut",
    "type_name",         "testVelocity3DOut",
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
testVelocity3DOut::testVelocity3DOut(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_outOut("out", m_out)
    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
testVelocity3DOut::~testVelocity3DOut()
{
}



RTC::ReturnCode_t testVelocity3DOut::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  
  // Set OutPort buffer
  addOutPort("out", m_outOut);

  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // </rtc-template>

  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t testVelocity3DOut::onFinalize()
{
  return RTC::RTC_OK;
}
*/


//RTC::ReturnCode_t testVelocity3DOut::onStartup(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t testVelocity3DOut::onShutdown(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t testVelocity3DOut::onActivated(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t testVelocity3DOut::onDeactivated(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


RTC::ReturnCode_t testVelocity3DOut::onExecute(RTC::UniqueId /*ec_id*/)
{
  static int count = 0;
  m_out.data.vx = static_cast<double>(count);
  m_out.data.vy = static_cast<double>(count+1);
  m_out.data.vz = static_cast<double>(count+2);
  m_out.data.vr = static_cast<double>(count+3);
  m_out.data.vp = static_cast<double>(count+4);
  m_out.data.va = static_cast<double>(count+5);
  count+=6;

  m_outOut.write();
  return RTC::RTC_OK;
}


//RTC::ReturnCode_t testVelocity3DOut::onAborting(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t testVelocity3DOut::onError(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t testVelocity3DOut::onReset(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t testVelocity3DOut::onStateUpdate(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t testVelocity3DOut::onRateChanged(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}



extern "C"
{
 
  void testVelocity3DOutInit(RTC::Manager* manager)
  {
    coil::Properties profile(testvelocity3dout_spec);
    manager->registerFactory(profile,
                             RTC::Create<testVelocity3DOut>,
                             RTC::Delete<testVelocity3DOut>);
  }
  
}
