//
//  SMBCloudSDKDeviceOSDFont.h
//  SMBCloudSDK
//
//  Created by W0116911 on 2024/2/27.
//

#import <Foundation/Foundation.h>
#import <SMBCloudSDK/SMBCloudSDKDeviceOSDEnum.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @brief IPC设备字体的OSD信息
 */
@interface SMBCloudSDKDeviceOSDFont: NSObject

/**
 * @brief 字体颜色类型
 * @see SMBCloudSDKDeviceOSDColorType
 */
@property (nonatomic, copy) SMBCloudSDKDeviceOSDColorType colorType;

/**
 * @brief 字体显示
 * @see SMBCloudSDKDeviceOSDSupportedDisplayMode
 */
@property (nonatomic, copy) SMBCloudSDKDeviceOSDSupportedDisplayMode display;

/**
 * @brief 字体颜色
 * @see SMBCloudSDKDeviceOSDSupportedColor
 */
@property (nonatomic, copy) SMBCloudSDKDeviceOSDSupportedColor color;

/**
 * @brief 字体大小
 * @see SMBCloudSDKDeviceOSDSupportedFontSize
 */
@property (nonatomic, copy) SMBCloudSDKDeviceOSDSupportedFontSize size;

@end

NS_ASSUME_NONNULL_END
