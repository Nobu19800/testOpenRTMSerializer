#include <rtm/ByteDataStreamBase.h>
#include <rtm/idl/BasicDataTypeSkel.h>
#include <rtm/idl/ExtendedDataTypesSkel.h>
#include <coil/Factory.h>
#include <rtm/Manager.h>
#include <rtm/ext/ROS2Transport/ROS2Serializer.h>
#include <geometry_msgs/msg/twist_stamped.hpp>
#if (STD_MSGS_VERSION_MAJOR >= 2)
#include <geometry_msgs/msg/detail/twist_stamped__rosidl_typesupport_fastrtps_cpp.hpp>
#else
#include <geometry_msgs/msg/twist_stamped__rosidl_typesupport_fastrtps_cpp.hpp>
#endif


//以下はシリアライザの実装
class TestRos2Serializer : public RTC::ROS2SerializerBase<RTC::TimedVelocity3D>
{
public:
    TestRos2Serializer(){};

    
 
    bool serialize(const RTC::TimedVelocity3D& data) override
    {
        geometry_msgs::msg::TwistStamped msg;
        msg.header.stamp.sec = data.tm.sec;
        msg.header.stamp.nanosec = data.tm.nsec;
        msg.twist.linear.x = data.data.vx;
        msg.twist.linear.y = data.data.vy;
        msg.twist.linear.z = data.data.vz;
        msg.twist.angular.x = data.data.vr;
        msg.twist.angular.y = data.data.vp;
        msg.twist.angular.z = data.data.va;
        

        return RTC::ROS2SerializerBase<RTC::TimedVelocity3D>::geometrymsg_serialize(msg);
    }
    bool deserialize(RTC::TimedVelocity3D& data) override
    {
        geometry_msgs::msg::TwistStamped msg;
        bool ret = ROS2SerializerBase<RTC::TimedVelocity3D>::geometrymsg_deserialize(msg);
        
        data.tm.sec = msg.header.stamp.sec;
        data.tm.nsec = msg.header.stamp.nanosec;
        data.data.vx = msg.twist.linear.x;
        data.data.vy = msg.twist.linear.y;
        data.data.vz = msg.twist.linear.z;
        data.data.vr = msg.twist.angular.x;
        data.data.vp = msg.twist.angular.y;
        data.data.va = msg.twist.angular.z;
        

        return ret;
    }
private:

};


extern "C"
{
    //以下はモジュールロード時に呼び出される関数
    DLL_EXPORT void TestRos2SerializerInit(RTC::Manager* /*manager*/)
    {
        //シリアライザの登録
        RTC::addRos2Serializer<RTC::TimedVelocity3D, geometry_msgs::msg::TwistStamped, TestRos2Serializer>("ros2:geometry_msgs/TwistStamped");
    }
}
