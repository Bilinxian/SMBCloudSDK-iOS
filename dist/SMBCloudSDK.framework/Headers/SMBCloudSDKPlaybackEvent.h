//
//  SMBCloudPlaybackEvent.h
//  Pods
//
//  Created by yishuqi on 2024/2/22.
//

#import <SMBCloudSDK/SMBCloudSDKPlaybackManagerDefines.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @brief 设备回放事件信息
 *
 */
@interface SMBCloudSDKPlaybackEvent : NSObject

/**@brief 回放事件开始时间**/
@property (nonatomic, copy, readonly) NSDate *startTime;
/**@brief 回放事件结束时间**/
@property (nonatomic, copy, readonly) NSDate *endTime;
/**@brief 回放录像类型**/
@property (nonatomic, copy, readonly) NSArray<NSNumber *> *videoType;
/**@brief 录像存储类型**/
@property (nonatomic, readonly) SMBCloudSDKStorageType videoStorageType;
/**@brief 录像存储设备名称**/
@property (nonatomic, copy, readonly) NSString * videoStorageName;
/**@brief 录像存储设备Id**/
@property (nonatomic, copy, readonly) NSString * videoStorageId;

- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
