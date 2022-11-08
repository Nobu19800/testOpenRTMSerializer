#include <rtm/ByteDataStreamBase.h>
#include <rtm/idl/BasicDataTypeSkel.h>
#include <rtm/idl/ExtendedDataTypesSkel.h>
#include <coil/Factory.h>
#include <rtm/Manager.h>
#include <rtm/ext/ROSTransport/ROSSerializer.h>
#include <geometry_msgs/TwistStamped.h>

//以下はシリアライザの実装
class TestRosSerializer : public RTC::ROSSerializerBase<RTC::TimedVelocity3D>
{
public:
    TestRosSerializer(){};

    
 
    bool serialize(const RTC::TimedVelocity3D& data) override
    {
        geometry_msgs::TwistStamped msg;
        msg.header.stamp.sec = data.tm.sec;
        msg.header.stamp.nsec = data.tm.nsec;
        msg.twist.linear.x = data.data.vx;
        msg.twist.linear.y = data.data.vy;
        msg.twist.linear.z = data.data.vz;
        msg.twist.angular.x = data.data.vr;
        msg.twist.angular.y = data.data.vp;
        msg.twist.angular.z = data.data.va;

        RTC::ROSSerializerBase<RTC::TimedVelocity3D>::m_message = ros::serialization::serializeMessage<geometry_msgs::TwistStamped>(msg);
        return true;
    }
    bool deserialize(RTC::TimedVelocity3D& data) override
    {
        geometry_msgs::TwistStamped msg;
        ros::serialization::deserializeMessage(ROSSerializerBase<RTC::TimedVelocity3D>::m_message, msg);
        data.tm.sec = msg.header.stamp.sec;
        data.tm.nsec = msg.header.stamp.nsec;
        data.data.vx = msg.twist.linear.x;
        data.data.vy = msg.twist.linear.y;
        data.data.vz = msg.twist.linear.z;
        data.data.vr = msg.twist.angular.x;
        data.data.vp = msg.twist.angular.y;
        data.data.va = msg.twist.angular.z;

        return true;
    }
private:

};

extern "C"
{
    //以下はモジュールロード時に呼び出される関数
    DLL_EXPORT void TestRosSerializerInit(RTC::Manager* /*manager*/)
    {
        //シリアライザの登録
        RTC::addRosSerializer<RTC::TimedVelocity3D, geometry_msgs::TwistStamped, TestRosSerializer>("ros:geometry_msgs/TwistStamped");
    }
}