//
//  SMBCloudSDKDeviceOSDCapability.h
//  SMBCloudSDK
//
//  Created by W0116911 on 2024/2/22.
//

#import <Foundation/Foundation.h>
#import <SMBCloudSDK/SMBCloudSDKDeviceOSDEnum.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @brief IPC设备OSD能力集
 */
@interface SMBCloudSDKDeviceOSDCapability : NSObject

/**
 * @brief 设备支持的自定义字符条数。第一个自定义字符也叫通道名称
 */
@property (nonatomic, readonly) NSInteger labelInfoNum;

/**
 * @brief 每个自定义字符支持的最大字符长度。以中文计算，一个中文字符相当两个英文字符。
 */
@property (nonatomic, strong, readonly) NSArray<NSNumber *> *labelInfoMaxLength;

/**
 * @brief 坐标是否锁定。自定义字符、date、week的坐标不能更改。
 */
@property (nonatomic, readonly) BOOL positionLock;

/**
 * @brief 是否支持日期显示。当不支持时，默认不显示且不允许修改成显示。
 */
@property (nonatomic, readonly) BOOL dateSupport;

/**
 * @brief 是否支持星期显示。当不支持时，默认不显示且不允许修改成显示。
 */
@property (nonatomic, readonly) BOOL weekSupport;

/**
 * @brief 支持的显示模式
 * @see SMBCloudSDKDeviceOSDSupportedDisplayMode
 */
@property (nonatomic, copy, readonly) NSArray<SMBCloudSDKDeviceOSDSupportedDisplayMode> *displayMode;

/**
 * @brief 设备支持设置的字体大小
 * @see SMBCloudSDKDeviceOSDSupportedFontSize
 */
@property (nonatomic, copy, readonly) NSArray<SMBCloudSDKDeviceOSDSupportedFontSize> *fontSize;

/**
 * @brief 设备支持的OSD字体颜色
 * @see SMBCloudSDKDeviceOSDSupportedColor
 */
@property (nonatomic, copy, readonly) NSArray<SMBCloudSDKDeviceOSDSupportedColor> *fontColor;

/**
 * @brief 是否支持通道名称和设备名称的联动
 */
@property (nonatomic, readonly) BOOL linkChnToDevSupport;

/**
 * @brief 是否支持镜头倍数显示信息修改
 */
@property (nonatomic, readonly) BOOL zoomSupport;

/**
 * @brief 支持的镜头调节倍数OSD的显示模式
 * @see SMBCloudSDKDeviceOSDSupportedDisplayRange
 */
@property (nonatomic, copy, readonly) NSArray<SMBCloudSDKDeviceOSDSupportedDisplayRange> *zoomDisplayRange;

/**
 * @brief 是否支持方位角显示信息修改
 */
@property (nonatomic, readonly) BOOL azimuthSupport;

/**
 * @brief 支持的方位角OSD的显示模式
 * @see SMBCloudSDKDeviceOSDSupportedDisplayRange
 */
@property (nonatomic, copy, readonly) NSArray<SMBCloudSDKDeviceOSDSupportedDisplayRange> *azimuthDisplayRange;

/**
 * @brief 是否支持预置点显示信息修改
 */
@property (nonatomic, readonly) BOOL presetSupport;

/**
 * @brief 支持的预置点信息的显示模式
 * @see SMBCloudSDKDeviceOSDSupportedDisplayRange
 */
@property (nonatomic, copy, readonly) NSArray<SMBCloudSDKDeviceOSDSupportedDisplayRange> *presetDisplayRange;

/**
 * @brief 是否支持当所有“自定义字符”个数超过一定数量时，限制字体大小到64*64
 */
@property (nonatomic, readonly) BOOL limitSizeTo64Support;

/**
 * @brief 自定义OSD条目是否支持对齐方式
 */
@property (nonatomic, readonly) BOOL labelInfoAlignSupport;

/**
 * @brief 是否支持电池电量osd显示
 */
@property (nonatomic, readonly) BOOL batteryLevelSupport;

@end

NS_ASSUME_NONNULL_END
