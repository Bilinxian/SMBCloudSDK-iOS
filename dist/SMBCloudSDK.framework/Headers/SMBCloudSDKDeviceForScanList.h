//
//  SMBCloudSDKDeviceForScanList.h
//  Pods
//
//  Created by chenkairong on 2023/9/22.
//

#import <Foundation/Foundation.h>
#import <SMBCloudSDK/SMBCloudSDKDeviceType.h>
#import <SMBCloudSDK/SMBCloudSDKDeviceAddEnumDefines.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @brief 局域网发现的设备对象结构
 */
@interface SMBCloudSDKDeviceForScanList : NSObject

- (instancetype)init NS_UNAVAILABLE;

/**
 * @brief 设备IP地址
 */
@property (nonatomic, copy, readonly) NSString *ip;

/**
 * @brief 设备MAC地址
 */
@property (nonatomic, copy, readonly) NSString *mac;

/**
 * @brief 设备标识
 */
@property (nonatomic, copy, readonly) NSString *identifier;

/**
 * @brief 设备HTTP端口号
 */
@property (nonatomic, assign, readonly) NSInteger httpPort;

/**
 * @brief 设备类型
 * @see SMBCloudSDKDeviceType
 */
@property (nonatomic, assign, readonly) SMBCloudSDKDeviceType deviceType;

/**
 * @brief 设备子类型
 * @see SMBCloudSDKDeviceSubType
 */
@property (nonatomic, assign, readonly) SMBCloudSDKDeviceSubType deviceSubType;

/**
 * @brief 设备激活类型
 * @see SMBCloudSDKDeviceActivateType
 */
@property (nonatomic, assign, readonly) SMBCloudSDKDeviceActivateType deviceActivateType;

/**
 * @brief 设备二维码
 */
@property (nonatomic, copy, readonly) NSString *qrCode;

/**
 * @brief 设备名称
 */
@property (nonatomic, copy, readonly) NSString *alias;

/**
 * @brief 设备型号
 */
@property (nonatomic, copy, readonly) NSString *model;

/**
 * @brief 设备特征类型
 */
@property (nonatomic, readonly) SMBCloudSDKDeviceFeatureType featureType;

/**
 * @brief 是否已被添加
 */
@property (nonatomic, assign, readonly) BOOL isAddedToDeviceList;

@end

NS_ASSUME_NONNULL_END
