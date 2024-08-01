//
//  SMBCloudSDKDeviceListFilterOrParam.h
//  SMBCloudSDK
//
//  Created by qinshiji on 2024/2/5.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @brief 设备列表请求filterOr参数
*/
@interface SMBCloudSDKDeviceListFilterOrParam: NSObject

/**
 * @brief 设备名称模糊查询。可传空值，表示该参数无效。默认为空值。
*/
@property (nonatomic, nullable, copy) NSString *deviceNameLike;

/**
 * @brief 设备型号模糊查询。可传空值，表示该参数无效。默认为空值。
*/
@property (nonatomic, nullable, copy) NSString *deviceModelLike;

/**
 * @brief ip地址模糊查询。可传空值，表示该参数无效。默认为空值。
*/
@property (nonatomic, nullable, copy) NSString *ipLike;

/**
 * @brief mac地址模糊查询。可传空值，表示该参数无效。默认为空值。
*/
@property (nonatomic, nullable, copy) NSString *macLike;

/**
 * @brief 分组名称模糊查询。可传空值，表示该参数无效。默认为空值。
*/
@property (nonatomic, nullable, copy) NSString *regionNameLike;

@end

NS_ASSUME_NONNULL_END
