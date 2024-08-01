//
//  SMBCloudSDKPlayerAllStatus.h
//  Pods
//
//  Created by Li Weijian on 2023/9/23.
//

#import <Foundation/Foundation.h>
#import <SMBCloudSDK/SMBCloudSDKPlayerDefines.h>
#import <SMBCloudSDK/SMBCloudSDKPlayerFinishInfo.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @brief 播放器播放状态
 *
 */
@interface SMBCloudSDKPlayerPlayStatus : NSObject

- (instancetype)init NS_UNAVAILABLE;

/**
 * @brief 播放状态
 * @see SMBCloudSDKPlayerStatus
 */
@property (nonatomic, readonly) SMBCloudSDKPlayerStatus playerStatus;
/**
 * @brief 通道状态
 * @see SMBCloudSDKPlayerStatus
 */
@property (nonatomic, readonly) SMBCloudSDKPlayerStatus channelStatus;

/**
 * @brief 播放结束信息
 *
 */
@property (nonatomic) SMBCloudSDKPlayerFinishInfo *channelFinishInfo;

/**
 * @brief 加载进度
 *
 */
@property (nonatomic, readonly) CGFloat loadingProgress;
/**
 * @brief 清晰度
 * @see SMBCloudSDKPlayerResolution
 */
@property (nonatomic, readonly) SMBCloudSDKPlayerResolution resolution;

@end

/**
 * @brief 播放器音量状态
 *
 */
@interface SMBCloudSDKPlayerVolumeStatus : NSObject

- (instancetype)init NS_UNAVAILABLE;
/**
 * @brief 播放器音量
 *
 */
@property (nonatomic, readonly) NSInteger playVolume;
/**
 * @brief 录像音量
 *
 */
@property (nonatomic, readonly) NSInteger recordVolume;

@end

/**
 * @brief 播放器截图状态
 *
 */
@interface SMBCloudSDKPlayerSnapshotStatus : NSObject

- (instancetype)init NS_UNAVAILABLE;

/**
 * @brief 是否正在截图
 *
 */
@property (nonatomic, readonly) BOOL isSnapshoting;
/**
 * @brief 截图路径
 *
 */
@property (nonatomic, readonly, copy) NSString *snapshotUrl;
/**
 * @brief 截图结束原因
 * @see SMBCloudSDKPlayerSnapshotFinishReason
 */
@property (nonatomic, readonly) SMBCloudSDKPlayerSnapshotFinishReason snapshotFinishReason;
/**
 * @brief 截图类型
 * @see SMBCloudSDKPlayerSnapshotType
 */
@property (nonatomic, readonly) SMBCloudSDKPlayerSnapshotType snapshotType;

@end

/**
 * @brief 播放器录像状态
 *
 */
@interface SMBCloudSDKPlayerRecordStatus : NSObject

- (instancetype)init NS_UNAVAILABLE;
/**
 * @brief 是否正在录像
 *
 */
@property (nonatomic, readonly) BOOL isRecording;
/**
 * @brief 录像路径
 *
 */
@property (nonatomic, readonly, copy) NSString *recordUrl;
/**
 * @brief 录像结束原因
 * @see SMBCloudSDKPlayerRecordFinishReason
 */
@property (nonatomic, readonly) SMBCloudSDKPlayerRecordFinishReason recordFinishReason;

@end


NS_ASSUME_NONNULL_END
