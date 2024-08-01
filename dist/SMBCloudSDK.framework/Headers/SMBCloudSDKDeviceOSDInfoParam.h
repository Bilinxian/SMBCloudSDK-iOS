//
//  SMBCloudSDKDeviceOSDInfoParam.h
//  SMBCloudSDK
//
//  Created by W0116911 on 2024/2/22.
//

#import <Foundation/Foundation.h>
#import <SMBCloudSDK/SMBCloudSDKDeviceOSDCoordinate.h>
#import <SMBCloudSDK/SMBCloudSDKDeviceOSDFont.h>
#import <SMBCloudSDK/SMBCloudSDKDeviceOSDLabelInfo.h>
#import <SMBCloudSDK/SMBCloudSDKDeviceOSDInfo.h>

NS_ASSUME_NONNULL_BEGIN

@interface SMBCloudSDKDeviceOSDInfoParam : SMBCloudSDKDeviceOSDInfo

/**
 * @brief 日期OSD信息
 * @see SMBCloudSDKDeviceOSDCoordinate
 */
@property (nonatomic, strong) SMBCloudSDKDeviceOSDCoordinate *date;

/**
 * @brief 星期OSD信息
 * @see SMBCloudSDKDeviceOSDCoordinate
 */
@property (nonatomic, strong) SMBCloudSDKDeviceOSDCoordinate *week;

/**
 * @brief 字体OSD信息
 * @see SMBCloudSDKDeviceOSDFont
 */
@property (nonatomic, strong) SMBCloudSDKDeviceOSDFont *font;

/**
 * @brief 自定义字符串OSD信息
 * @see SMBCloudSDKDeviceOSDLabelInfo
 */
@property (nonatomic, copy) NSArray<SMBCloudSDKDeviceOSDLabelInfo *> *labelInfoList;

- (instancetype)initWithDeviceOSDInfo:(SMBCloudSDKDeviceOSDInfo *)osdInfo;

@end

NS_ASSUME_NONNULL_END
