// -*- C++ -*-
// <rtc-template block="description">
/*!
 * @file  testVelocity3DIn.cpp
 * @brief TimedVelocity3D type test component.
 *
 */
// </rtc-template>

#include "testVelocity3DIn.h"

// Module specification
// <rtc-template block="module_spec">
#if RTM_MAJOR_VERSION >= 2
static const char* const testvelocity3din_spec[] =
#else
static const char* testvelocity3din_spec[] =
#endif
  {
    "implementation_id", "testVelocity3DIn",
    "type_name",         "testVelocity3DIn",
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
testVelocity3DIn::testVelocity3DIn(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_inIn("in", m_in)
    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
testVelocity3DIn::~testVelocity3DIn()
{
}



RTC::ReturnCode_t testVelocity3DIn::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("in", m_inIn);
  
  // Set OutPort buffer

  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // </rtc-template>

  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t testVelocity3DIn::onFinalize()
{
  return RTC::RTC_OK;
}
*/


//RTC::ReturnCode_t testVelocity3DIn::onStartup(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t testVelocity3DIn::onShutdown(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t testVelocity3DIn::onActivated(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t testVelocity3DIn::onDeactivated(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


RTC::ReturnCode_t testVelocity3DIn::onExecute(RTC::UniqueId /*ec_id*/)
{
  if(m_inIn.isNew())
  {
    m_inIn.read();
    std::cout << m_in.data.vx << " " << m_in.data.vy << " " << m_in.data.vz << " " << 
                m_in.data.vr << " " << m_in.data.vp << " " << m_in.data.va << std::endl;
  }
  return RTC::RTC_OK;
}


//RTC::ReturnCode_t testVelocity3DIn::onAborting(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t testVelocity3DIn::onError(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t testVelocity3DIn::onReset(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t testVelocity3DIn::onStateUpdate(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t testVelocity3DIn::onRateChanged(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}



extern "C"
{
 
  void testVelocity3DInInit(RTC::Manager* manager)
  {
    coil::Properties profile(testvelocity3din_spec);
    manager->registerFactory(profile,
                             RTC::Create<testVelocity3DIn>,
                             RTC::Delete<testVelocity3DIn>);
  }
  
}
