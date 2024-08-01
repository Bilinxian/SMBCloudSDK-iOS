//
//  SMBCloudSDKDeviceOSDInfo.h
//  SMBCloudSDK
//
//  Created by W0116911 on 2024/2/22.
//

#import <Foundation/Foundation.h>
#import <SMBCloudSDK/SMBCloudSDKDeviceOSDCoordinate.h>
#import <SMBCloudSDK/SMBCloudSDKDeviceOSDFont.h>
#import <SMBCloudSDK/SMBCloudSDKDeviceOSDLabelInfo.h>

NS_ASSUME_NONNULL_BEGIN

@interface SMBCloudSDKDeviceOSDInfo : NSObject

/**
 * @brief 日期OSD信息
 * @see SMBCloudSDKDeviceOSDCoordinate
 */
@property (nonatomic, strong, readonly) SMBCloudSDKDeviceOSDCoordinate *date;

/**
 * @brief 星期OSD信息
 * @see SMBCloudSDKDeviceOSDCoordinate
 */
@property (nonatomic, strong, readonly) SMBCloudSDKDeviceOSDCoordinate *week;

/**
 * @brief 字体OSD信息
 * @see SMBCloudSDKDeviceOSDFont
 */
@property (nonatomic, strong, readonly) SMBCloudSDKDeviceOSDFont *font;

/**
 * @brief 自定义字符串OSD信息
 * @see SMBCloudSDKDeviceOSDLabelInfo
 */
@property (nonatomic, copy, readonly) NSArray<SMBCloudSDKDeviceOSDLabelInfo *> *labelInfoList;

@end

NS_ASSUME_NONNULL_END
