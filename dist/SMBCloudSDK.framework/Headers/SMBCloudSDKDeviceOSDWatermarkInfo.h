//
//  SMBCloudSDKDeviceOSDWatermarkInfo.h
//  SMBCloudSDK
//
//  Created by W0116911 on 2024/2/27.
//

#import <Foundation/Foundation.h>
#import <SMBCloudSDK/SMBCloudSDKDeviceOSDEnum.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @brief OSD数字水印基本信息
*/
@interface SMBCloudSDKDeviceOSDWatermarkBasicInfo : NSObject

/**
 * @brief 动态OSD最大行数。取值范围1-16。
 */
@property (nonatomic) NSInteger maxLabelNumber;
/**
 * @brief 静态OSD最大条数。取值范围1-3。
 */
@property (nonatomic) NSInteger maxSolidSequence;
/**
 * @brief OSD颜色
 * @see SMBCloudSDKDeviceOSDWatermarkColor
 */
@property (nonatomic, copy) SMBCloudSDKDeviceOSDWatermarkColor color;
/**
 * @brief OSD字号
 * @see SMBCloudSDKDeviceOSDWatermarkFontSize
 */
@property (nonatomic) SMBCloudSDKDeviceOSDWatermarkFontSize fontSize;

@end

/**
 * @brief OSD数字水印动态字符串信息
*/
@interface SMBCloudSDKDeviceOSDWatermarkDynamicLabelInfo : NSObject

/**
 * @brief OSD显示字符串
 */
@property (nonatomic, copy) NSString *content;
/**
 * @brief OSD显示左上角横坐标。取值范围0-10000。
 */
@property (nonatomic) NSInteger horizontalCoordinate;
/**
 * @brief OSD显示左上角纵坐标。取值范围0-10000。
 */
@property (nonatomic) NSInteger verticalCoordinate;

@end

/**
 * @brief OSD数字水印静态字符串信息
*/
@interface SMBCloudSDKDeviceOSDWatermarkSolidLabelInfo : SMBCloudSDKDeviceOSDWatermarkDynamicLabelInfo

/**
 * @brief 目标静态OSD显示行下标
 */
@property (nonatomic) NSInteger sequence;

/**
 * @brief 显示
 * @see SMBCloudSDKDeviceOSDIfStatus
 */
@property (nonatomic) SMBCloudSDKDeviceOSDIfStatus showStatus;

@end

NS_ASSUME_NONNULL_END
