//
//  SMBCloudSDKDeviceTypeEnum.h
//  SMBCloudSDK
//
//  Created by qinshiji on 2024/3/21.
//


NS_ASSUME_NONNULL_BEGIN

/**
 * @brief 设备类型
 */
typedef NS_ENUM(NSInteger, SMBCloudSDKDeviceType) {
    /** @brief 设备类型：未知 */
    SMBCloudSDKDeviceTypeUnknownType = -1,
    /** @brief 设备类型：IPC */
    SMBCloudSDKDeviceTypeIpc = 0,
    /** @brief 设备类型：NVR */
    SMBCloudSDKDeviceTypeNvr = 1,
};

NS_ASSUME_NONNULL_END
