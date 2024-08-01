//
//  SMBCloudSDKOnboardWiFiInfo.h
//  Pods
//
//  Created by chenkairong on 2023/9/22.
//

#import <Foundation/Foundation.h>
#import <SMBCloudSDK/SMBCloudSDKDeviceAddEnumDefines.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @brief 配网WIFI信息
 */
@interface SMBCloudSDKOnboardWiFiInfo : NSObject

- (instancetype)init NS_UNAVAILABLE;

/**
 * @brief WI-FI SSID
 */
@property (nonatomic, copy, readonly) NSString *ssid;

/**
 * @brief WI-FI 密码
 */
@property (nonatomic, copy) NSString *password;

/**
 * @brief WI-FI BSSID
 */
@property (nonatomic, readonly) SInt64 bssid;

/**
 * @brief WI-FI 认证类型
 * @see SMBCloudSDKOnboardWiFiAuthType
 */
@property (nonatomic, readonly) SMBCloudSDKOnboardWiFiAuthType authenticated;

/**
 * @brief WI-FI 加密类型
 * @see SMBCloudSDKOnboardWiFiEncryptType
 */
@property (nonatomic, readonly) SMBCloudSDKOnboardWiFiEncryptType encrypted;

/**
 * @brief WI-FI 信号强度
 */
@property (nonatomic, readonly) NSInteger rssi;

// 一体机
/**
 * @brief WI-FI 接收信号强度（dBm）,-120dBm-0dBm
 */
@property (nonatomic, readonly) NSInteger signal;

/**
 * @brief 设备名称
 */
@property (nonatomic, copy, readonly) NSString *deviceName;

@end

NS_ASSUME_NONNULL_END

