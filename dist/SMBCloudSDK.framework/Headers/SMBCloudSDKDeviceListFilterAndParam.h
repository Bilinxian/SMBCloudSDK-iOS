//
//  SMBCloudSDKDeviceListFilterAndParam.h
//  SMBCloudSDK
//
//  Created by qinshiji on 2024/2/5.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @brief 设备列表请求filterAnd参数
*/
@interface SMBCloudSDKDeviceListFilterAndParam: NSObject

/**
 * @brief 分组id。可空，为空值时该参数无效。默认为空值。
*/
@property (nonatomic, nullable, copy) NSString *regionId;

/**
 * @brief 设备状态，传SMBCloudSDKDeviceStatus的枚举值。可空，为空值时该参数无效。默认为空值。
*/
@property (nonatomic, nullable, copy) NSNumber *deviceStatus;

/**
 * @brief ip地址下限。可空，为空值时该参数无效。默认为空值。
*/
@property (nonatomic, nullable, copy) NSString *ipFloor;

/**
 * @brief ip地址上限。可空，为空值时该参数无效。默认为空值。
*/
@property (nonatomic, nullable, copy) NSString *ipCeilling;

/**
 * @brief 是否获取子设备，即NVR下的通道IPC。默认为false
*/
@property (nonatomic) BOOL hasChild;

/**
 * @brief 设备类型列表，传SMBCloudSDKDeviceType的枚举值列表。可空，为空值时该参数无效。默认为空值。
*/
@property (nonatomic, nullable, copy) NSSet <NSNumber *> *deviceTypes;

@end


NS_ASSUME_NONNULL_END
