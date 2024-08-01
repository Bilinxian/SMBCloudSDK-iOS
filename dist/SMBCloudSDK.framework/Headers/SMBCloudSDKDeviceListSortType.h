//
//  SMBCloudSDKDeviceListSortType.h
//  SMBCloudSDK
//
//  Created by qinshiji on 2024/2/5.
//

#import <Foundation/Foundation.h>
#import <SMBCloudSDK/SMBCloudSDKDeviceEnum.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @brief 设备列表请求排序参数
*/
@interface SMBCloudSDKDeviceListSortType: NSObject

/**
 * @brief 排序key值
 * @see SMBCloudSDKDeviceListSortKey
*/
@property (nonatomic, readonly) SMBCloudSDKDeviceListSortKey key;

/**
 * @brief 排序value值
 * @see SMBCloudSDKDeviceListSortValue
*/
@property (nonatomic, readonly) SMBCloudSDKDeviceListSortValue value;

// 对外仅提供带参数的init方法
- (instancetype)init NS_UNAVAILABLE;

/**
 * @brief 初始化
 * @param key 排序key值
 * @param value 排序value值
 * @see SMBSDKDeviceListSortKey
 * @see SMBSDKDeviceListSortValue
 */
- (instancetype)initWithKey:(SMBCloudSDKDeviceListSortKey)key
                      value:(SMBCloudSDKDeviceListSortValue)value;
@end

NS_ASSUME_NONNULL_END
