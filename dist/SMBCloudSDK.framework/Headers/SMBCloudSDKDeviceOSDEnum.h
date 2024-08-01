//
//  SMBCloudSDKDeviceOSDEnum.h
//  SMBCloudSDK
//
//  Created by W0116911 on 2024/2/23.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @brief 支持的显示模式列表
 **/
typedef NSString *SMBCloudSDKDeviceOSDSupportedDisplayMode NS_STRING_ENUM;
/** @brief OSD显示模式：不透明，不闪烁 **/
FOUNDATION_EXPORT SMBCloudSDKDeviceOSDSupportedDisplayMode const SMBCloudSDKDeviceOSDSupportedDisplayModeNtnb;
/** @brief OSD显示模式：透明，不闪烁 **/
FOUNDATION_EXPORT SMBCloudSDKDeviceOSDSupportedDisplayMode const SMBCloudSDKDeviceOSDSupportedDisplayModeTnb;
/** @brief OSD显示模式：不透明，闪烁 **/
FOUNDATION_EXPORT SMBCloudSDKDeviceOSDSupportedDisplayMode const SMBCloudSDKDeviceOSDSupportedDisplayModeNtb;
/** @brief OSD显示模式：透明，闪烁 **/
FOUNDATION_EXPORT SMBCloudSDKDeviceOSDSupportedDisplayMode const SMBCloudSDKDeviceOSDSupportedDisplayModeTb;

/**
 * @brief 设备支持设置的字体大小
 **/
typedef NSString *SMBCloudSDKDeviceOSDSupportedFontSize NS_STRING_ENUM;
/** @brief OSD字号：auto */
FOUNDATION_EXPORT SMBCloudSDKDeviceOSDSupportedFontSize const SMBCloudSDKDeviceOSDSupportedFontSizeAuto;
/** @brief OSD字号：16*16 */
FOUNDATION_EXPORT SMBCloudSDKDeviceOSDSupportedFontSize const SMBCloudSDKDeviceOSDSupportedFontSizeSixteen;
/** @brief OSD字号：32*32 */
FOUNDATION_EXPORT SMBCloudSDKDeviceOSDSupportedFontSize const SMBCloudSDKDeviceOSDSupportedFontSizeThirtyTwo;
/** @brief OSD字号：48*48 */
FOUNDATION_EXPORT SMBCloudSDKDeviceOSDSupportedFontSize const SMBCloudSDKDeviceOSDSupportedFontSizeFourtyEight;
/** @brief OSD字号：64*64 */
FOUNDATION_EXPORT SMBCloudSDKDeviceOSDSupportedFontSize const SMBCloudSDKDeviceOSDSupportedFontSizeSixtyFour;

/**
 * @brief 设备支持的OSD字体颜色
 **/
typedef NSString *SMBCloudSDKDeviceOSDSupportedColor NS_STRING_ENUM;
/** @brief OSD字体颜色：auto */
FOUNDATION_EXPORT SMBCloudSDKDeviceOSDSupportedColor const SMBCloudSDKDeviceOSDSupportedColorAuto;
/** @brief OSD字体颜色：white */
FOUNDATION_EXPORT SMBCloudSDKDeviceOSDSupportedColor const SMBCloudSDKDeviceOSDSupportedColorWhite;
/** @brief OSD字体颜色：black */
FOUNDATION_EXPORT SMBCloudSDKDeviceOSDSupportedColor const SMBCloudSDKDeviceOSDSupportedColorBlack;
/** @brief OSD字体颜色：blue*/
FOUNDATION_EXPORT SMBCloudSDKDeviceOSDSupportedColor const SMBCloudSDKDeviceOSDSupportedColorBlue;
/** @brief OSD字体颜色：red */
FOUNDATION_EXPORT SMBCloudSDKDeviceOSDSupportedColor const SMBCloudSDKDeviceOSDSupportedColorRed;
/** @brief OSD字体颜色：green */
FOUNDATION_EXPORT SMBCloudSDKDeviceOSDSupportedColor const SMBCloudSDKDeviceOSDSupportedColorGreen;
/** @brief OSD字体颜色：yellow */
FOUNDATION_EXPORT SMBCloudSDKDeviceOSDSupportedColor const SMBCloudSDKDeviceOSDSupportedColorYellow;

/**
 *@brief 方位角/镜头调节倍数/预置点等OSD支持的显示模式
 **/
typedef NSString *SMBCloudSDKDeviceOSDSupportedDisplayRange NS_STRING_ENUM;
/** @brief OSD显示模式：显示2秒*/
FOUNDATION_EXPORT SMBCloudSDKDeviceOSDSupportedDisplayRange const SMBCloudSDKDeviceOSDSupportedDisplayRangeTwoSeconds;
/** @brief OSD显示模式：显示5秒 */
FOUNDATION_EXPORT SMBCloudSDKDeviceOSDSupportedDisplayRange const SMBCloudSDKDeviceOSDSupportedDisplayRangeFiveSeconds;
/** @brief OSD显示模式：显示10秒 */
FOUNDATION_EXPORT SMBCloudSDKDeviceOSDSupportedDisplayRange const SMBCloudSDKDeviceOSDSupportedDisplayRangeTenSeconds;
/** @brief OSD显示模式：一直不显示 */
FOUNDATION_EXPORT SMBCloudSDKDeviceOSDSupportedDisplayRange const SMBCloudSDKDeviceOSDSupportedDisplayRangeClose;
/** @brief OSD显示模式：一直显示 */
FOUNDATION_EXPORT SMBCloudSDKDeviceOSDSupportedDisplayRange const SMBCloudSDKDeviceOSDSupportedDisplayRangeOpen;

/**
 * @brief 设备的OSD字体颜色类型
 **/
// 底层没有对应枚举，由中间层定义。
typedef NSString *SMBCloudSDKDeviceOSDColorType NS_STRING_ENUM;
/** @brief 字体颜色类型：auto（默认） */
FOUNDATION_EXPORT SMBCloudSDKDeviceOSDColorType const SMBCloudSDKDeviceOSDColorTypeAuto;
/** @brief 字体颜色类型：user_defined （自定义） */
FOUNDATION_EXPORT SMBCloudSDKDeviceOSDColorType const SMBCloudSDKDeviceOSDColorTypeUserDefined;

/**
 * @brief  设备自定义字符串的 OSD 信息对齐方式
 **/
// 底层没有对应枚举，由中间层定义。
typedef NSString *SMBCloudSDKDeviceOSDLabelInfoAlignType NS_STRING_ENUM;
/** @brief 对齐方式：左对齐(默认)*/
FOUNDATION_EXPORT SMBCloudSDKDeviceOSDLabelInfoAlignType const SMBCloudSDKDeviceOSDLabelInfoAlignTypeLeft;
/** @brief 对齐方式：居中对齐 */
FOUNDATION_EXPORT SMBCloudSDKDeviceOSDLabelInfoAlignType const SMBCloudSDKDeviceOSDLabelInfoAlignTypeCenter;
/** @brief 对齐方式：右对齐 */
FOUNDATION_EXPORT SMBCloudSDKDeviceOSDLabelInfoAlignType const SMBCloudSDKDeviceOSDLabelInfoAlignTypeRight;

/**
 * @brief 设备日期/星期OSD信息显示状态、联动通道名称和设备名称状态。
*/
typedef NS_ENUM(NSInteger, SMBCloudSDKDeviceOSDIfStatus) {
    /** @brief 日期/星期OSD信息是否显示：否 */
    SMBCloudSDKDeviceOSDIfStatusFalse = 0,
    /** @brief 日期/星期OSD信息是否显示：是 */
    SMBCloudSDKDeviceOSDIfStatusTrue = 1,
    /** @brief 日期/星期OSD信息是否显示：不设置 */
    SMBCloudSDKDeviceOSDIfStatusDefault = 2
};

/**
 * @brief OSD 数字水印颜色。
*/
typedef NSString *SMBCloudSDKDeviceOSDWatermarkColor NS_STRING_ENUM;
/** @brief OSD颜色：白色 */
FOUNDATION_EXPORT SMBCloudSDKDeviceOSDWatermarkColor const SMBCloudSDKDeviceOSDWatermarkColorWhite;
/** @brief OSD颜色：黑色 */
FOUNDATION_EXPORT SMBCloudSDKDeviceOSDWatermarkColor const SMBCloudSDKDeviceOSDWatermarkColorBlack;
/** @brief OSD颜色：红色 */
FOUNDATION_EXPORT SMBCloudSDKDeviceOSDWatermarkColor const SMBCloudSDKDeviceOSDWatermarkColorRed;

/**
 * @brief OSD字号
*/
typedef NS_ENUM(NSInteger, SMBCloudSDKDeviceOSDWatermarkFontSize) {
    /** @brief OSD字号：无设置 */
    SMBCloudSDKDeviceOSDWatermarkFontSizeNone = -1,
    /** @brief OSD字号：16 */
    SMBCloudSDKDeviceOSDWatermarkFontSizeSixteen = 16,
    /** @brief OSD字号：32 */
    SMBCloudSDKDeviceOSDWatermarkFontSizeThirtyTwo = 32,
    /** @brief OSD字号：48 */
    SMBCloudSDKDeviceOSDWatermarkFontSizeFourtyEight = 48,
    /** @brief OSD字号：64 */
    SMBCloudSDKDeviceOSDWatermarkFontSizeSixtyFour = 64
};

/**
 * @brief 清除OSD内容的方式
*/
typedef NS_ENUM(NSInteger, SMBCloudSDKDeviceOSDCleanType) {
    /** @brief 清除OSD内容的方式：清空动态字符串 */
    SMBCloudSDKDeviceOSDCleanTypeDynamicLabel = 0,
    /** @brief 清除OSD内容的方式：清空静态字符串 */
    SMBCloudSDKDeviceOSDCleanTypeSolidLabel = 1,
    /** @brief 清除OSD内容的方式：清空动态和静态字符串 */
    SMBCloudSDKDeviceOSDCleanTypeDynamicSolidLabel = 2
};

NS_ASSUME_NONNULL_END
