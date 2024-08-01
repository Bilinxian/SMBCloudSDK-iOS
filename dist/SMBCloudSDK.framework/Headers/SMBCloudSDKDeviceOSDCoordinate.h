//
//  SMBCloudSDKDeviceOSDCoordinate.h
//  SMBCloudSDK
//
//  Created by W0116911 on 2024/2/22.
//

#import <Foundation/Foundation.h>
#import <SMBCloudSDK/SMBCloudSDKDeviceOSDEnum.h>

NS_ASSUME_NONNULL_BEGIN

@interface SMBCloudSDKDeviceOSDCoordinate : NSObject

/**
 * @brief 起点X坐标
 */
@property (nonatomic) NSInteger horizontalCoordinate;

/**
 * @brief 起点Y坐标
 */
@property (nonatomic) NSInteger verticalCoordinate;

/**
 * @brief 是否显示
 * @see SMBCloudSDKDeviceOSDIfStatus
 */
@property (nonatomic) SMBCloudSDKDeviceOSDIfStatus showStatus;

@end

NS_ASSUME_NONNULL_END
