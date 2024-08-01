//
//  SMBCloudSDKChannelDevice.h
//  SMBCloudSDK
//
//  Created by qinshiji on 2024/3/2.
//

#import <Foundation/Foundation.h>
#import <SMBCloudSDK/SMBCloudSDKDeviceEnum.h>
#import <SMBCloudSDK/SMBCloudSDKDeviceType.h>

NS_ASSUME_NONNULL_BEGIN

@interface SMBCloudSDKChannelDevice: NSObject

- (instancetype)init NS_UNAVAILABLE;

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
 * @brief 设备开放状态
 * @see SMBCloudSDKDeviceOpenStatus
*/
@property (nonatomic, readonly) SMBCloudSDKDeviceOpenStatus openStatus;

/**
 * @brief 设备型号
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
 * @brief 设备通道id。通道IPC的通道id从1开始计算，直至达到NVR的最大通道数
*/
@property (nonatomic, readonly) NSInteger channelId;


@end

NS_ASSUME_NONNULL_END
