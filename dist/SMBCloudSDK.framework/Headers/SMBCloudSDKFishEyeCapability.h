//
//  SMBCloudSDKFishEyeCapability.h
//  SMBCloudSDK
//
//  Created by qinshiji on 2024/4/11.
//

#import <Foundation/Foundation.h>
#import <SMBCloudSDK/SMBCloudSDKPreviewManagerDefines.h>
#import <SMBCloudSDK/SMBCloudSDKPlayerDefines.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @brief 鱼眼能力集
 *
 */
@interface SMBCloudSDKFishEyeCapability : NSObject
/**
 * @brief 鱼眼设备支持的物理安装模式
 * @discussion 设备支持鱼眼时，保证数组非空
 * @see SMBCloudSDKFishEyeSupportInstallMode
 */
@property (nonatomic, copy, readonly) NSArray<SMBCloudSDKFishEyeSupportInstallMode> *supportInstallModes;
/**
 * @brief 鱼眼设备顶装时支持的视频显示模式
 * @see SMBCloudSDKFishEyeDisplayMode
 */
@property (nonatomic, copy, readonly) NSArray<SMBCloudSDKFishEyeDisplayMode> *topDisplaymodes;
/**
 * @brief 鱼眼设备壁装时支持的视频显示模式
 * @see SMBCloudSDKFishEyeDisplayMode
 */
@property (nonatomic, copy, readonly) NSArray<SMBCloudSDKFishEyeDisplayMode> *wallDisplaymodes;
/**
 * @brief 无效的像素区域，用于拼接。范围0-4999
 */
@property (nonatomic, readonly) float invalidPixel;
/**@brief 视频有效画面中是否包含OSD**/
@property (nonatomic, readonly) BOOL osdInVideo;
/**@brief 画面类型**/
@property (nonatomic, readonly) SMBCloudSDKFishEyeVideoType videoType;
/**@brief 鱼眼设备输出视频是否已经中心校准 **/
@property (nonatomic, readonly) BOOL centerCalibration;
/**@brief 鱼眼设备输出视频中心点横坐标 。范围1-9999**/
@property (nonatomic, readonly) NSInteger circleCenterX;
/**@brief 鱼眼设备输出视频中心点纵坐标.范围1-9999 **/
@property (nonatomic, readonly) NSInteger circleCenterY;
/**@brief 成像半径。范围1-4999 **/
@property (nonatomic, readonly) NSInteger radius;

@end

NS_ASSUME_NONNULL_END
