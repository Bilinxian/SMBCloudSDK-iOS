//
//  SMBCloudSDKDevice.h
//  SMBCloudSDK
//
//  Created by qinshiji on 2024/3/22.
//

#import <Foundation/Foundation.h>
#import <SMBCloudSDK/SMBCloudSDKDeviceEnum.h>
#import <SMBCloudSDK/SMBCloudSDKDeviceType.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @brief 设备信息
*/
@interface SMBCloudSDKDevice: NSObject

// 对上层不提供默认的init方法
- (instancetype)init NS_UNAVAILABLE;

/**
 * @brief 设备二维码
*/
@property (nonatomic, copy, readonly) NSString *qrCode;

/**
 * @brief 设备名称
*/
@property (nonatomic, copy, readonly) NSString *deviceName;

/**
 * @brief 设备类型
 * @see SMBCloudSDKDeviceType
*/
@property (nonatomic, readonly) SMBCloudSDKDeviceType deviceType;

/**
 * @brief 设备状态
 * @see SMBCloudSDKDeviceStatus
*/
@property (nonatomic, readonly) SMBCloudSDKDeviceStatus deviceStatus;

/**
 * @brief 设备开放类型
 * @see SMBCloudSDKDeviceOpenType
*/
@property (nonatomic, readonly) SMBCloudSDKDeviceOpenType openType;

/**
 * @brief 设备开放状态
 * @see SMBCloudSDKDeviceOpenStatus
*/
@property (nonatomic, readonly) SMBCloudSDKDeviceOpenStatus openStatus;

/**
 * @brief 设备型号，NVR通道设备不含该字段。
*/
@property (nonatomic, copy, readonly) NSString *deviceModel;

/**
 * @brief 设备ip
*/
@property (nonatomic, copy, readonly) NSString *ip;

/**
 * @brief 设备mac地址
*/
@property (nonatomic, copy, readonly) NSString *mac;

/**
 * @brief 设备所属分组id。为"1"时表示设备未分组；为空字符串时表示当前位于设备型项目，无分组数据。
*/
@property (nonatomic, copy, readonly) NSString *regionId;

/**
 * @brief 设备所属分组名称。为空字符串时表示设备未分组或当前位于设备型项目，无分组数据。
*/
@property (nonatomic, copy, readonly) NSString *regionName;

/**
 * @brief 设备通道id。NVR本身的通道ID为-1，直连IPC的通道ID为1，通道IPC的通道id从1开始计算，直至达到NVR的最大通道数
*/
@property (nonatomic, readonly) NSInteger channelId;

/**
 * @brief 父设备mac地址
*/
@property (nonatomic, copy, readonly) NSString *parentMac;

/**
 * @brief 父设备二维码
*/
@property (nonatomic, copy, readonly) NSString *parentQrCode;

/**
 * @brief 是否为NVR通道设备
*/
@property (nonatomic, readonly) BOOL isNVRChannel;

/**
 * @brief 设备所属项目ID。为空字符串时表示当前位于设备型项目，无项目数据。
*/
@property (nonatomic, copy, readonly) NSString *projectId;

/**
 * @brief 设备所属项目名称。为空字符串时表示当前位于设备型项目，无项目数据。
*/
@property (nonatomic, copy, readonly) NSString *projectName;

/**
 * @brief 设备软件版本
*/
@property (nonatomic, copy, readonly) NSString *firmwareVer;

/**
 * @brief 设备硬件版本，NVR通道设备不含该字段。
*/
@property (nonatomic, copy, readonly) NSString *hardwareVer;

@end

NS_ASSUME_NONNULL_END
