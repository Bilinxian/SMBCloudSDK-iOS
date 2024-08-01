//
//  SMBCloudSDKDeviceEnum.h
//  SMBCloudSDK
//
//  Created by qinshiji on 2024/3/22.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @brief 设备状态
*/
typedef NS_ENUM(NSInteger, SMBCloudSDKDeviceStatus) {
    /** @brief 设备状态：未知 */
    SMBCloudSDKDeviceStatusUnknow = -1,
    /** @brief 设备状态：离线 */
    SMBCloudSDKDeviceStatusOffine = 0,
    /** @brief 设备状态：在线 */
    SMBCloudSDKDeviceStatusOnline = 1,
    /** @brief 设备状态：重启中 */
    SMBCloudSDKDeviceStatusRebooting = 2,
    /** @brief 设备状态：升级中 */
    SMBCloudSDKDeviceStatusUpgrading = 3,
    /** @brief 设备状态：配置中*/
    SMBCloudSDKDeviceStatusConfiguring = 4,
    /** @brief 设备状态：同步中 */
    SMBCloudSDKDeviceStatusSyncing = 5,
    /** @brief 设备状态：等待升级中 */
    SMBCloudSDKDeviceStatusWaitingUpgrade = 6
};

/**
 * @brief 设备开放类型
*/
typedef NS_ENUM(NSInteger, SMBCloudSDKDeviceOpenType) {
    /** @brief 设备开放类型：一般类型设备 */
    SMBCloudSDKDeviceOpenTypeNormal = 0,
    /** @brief 设备开放类型：视频类型设备 */
    SMBCloudSDKDeviceOpenTypeVideo = 1
};

/**
 * @brief 设备开放状态
*/
typedef NS_ENUM(NSInteger, SMBCloudSDKDeviceOpenStatus) {
    /** @brief 设备开放状态：受限关闭 */
    SMBCloudSDKDeviceOpenStatusClosed = 0,
    /** @brief 设备开放状态：试用中 */
    SMBCloudSDKDeviceOpenStatusProbation = 1,
    /** @brief 设备开放状态：正常使用中（付费使用中） */
    SMBCloudSDKDeviceOpenStatusNormal = 2
};

/**
 * @brief 设备列表请求排序Key值
*/
typedef NS_ENUM(NSInteger, SMBCloudSDKDeviceListSortKey) {
    /**@brief 设备列表请求排序Key值：设备类型 */
    SMBCloudSDKDeviceListSortKeyDeviceType = 1,
    /**@brief 设备列表请求排序Key值：设备状态 */
    SMBCloudSDKDeviceListSortKeyDeviceStatus = 2,
    /**@brief 设备列表请求排序Key值：ip */
    SMBCloudSDKDeviceListSortKeyIp = 3,
    /**@brief 设备列表请求排序Key值：mac地址 */
    SMBCloudSDKDeviceListSortKeyMac = 4,
    /**@brief 设备列表请求排序Key值：设备名称 */
    SMBCloudSDKDeviceListSortKeyDeviceName = 5
};

/**
 * @brief 设备列表请求排序Value值
*/
typedef NS_ENUM(NSInteger, SMBCloudSDKDeviceListSortValue) {
    /**@brief 设备列表请求排序Value值：升序 */
    SMBCloudSDKDeviceListSortValueAsc = 0,
    /**@brief 设备列表请求排序Value值：降序 */
    SMBCloudSDKDeviceListSortValueDesc = 1
};

NS_ASSUME_NONNULL_END
