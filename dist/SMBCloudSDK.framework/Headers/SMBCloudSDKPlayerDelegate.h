//
//  SMBCloudSDKPlayerDelegate.h
//  Pods
//
//  Created by Li Weijian on 2023/9/23.
//

#import <SMBCloudSDK/SMBCloudSDKPlayerDefines.h>
#import <SMBCloudSDK/SMBCloudSDKPlayerAllStatus.h>
#import <SMBCloudSDK/SMBCloudSDKPlayerTalkStatus.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @brief 播放器播放状态回调协议
 *
 */
@protocol SMBCloudSDKPlayerPlayDelegate <NSObject>

/**
 * @brief 播放视图已生成
 * @param displayView 生成的播放视图
 */
- (void)displayViewCreated:(UIView *)displayView;

/**
 * @brief 播放状态改变
 * @param playerStatus 播放状态
 * @see SMBCloudSDKPlayerPlayStatus
 */
- (void)playerStatusChange:(SMBCloudSDKPlayerPlayStatus *)playerStatus;

/**
 * @brief 对讲状态改变
 * @param talkStatus 对讲状态
 * @see SMBCloudSDKPlayerTalkStatus
 */
- (void)talkStatusChange:(SMBCloudSDKPlayerTalkStatus *)talkStatus;

/**
 * @brief 加载进度改变
 * @param progress 加载进度
 */
- (void)loadingProgressChange:(NSInteger)progress;

/**
 * @brief 播放时间改变
 * @param playTime 播放时间
 */
- (void)playTimeChange:(NSTimeInterval)playTime;

/**
 * @brief 清晰度改变
 * @param resolution 清晰度
 * @see SMBCloudSDKPlayerResolution
 */
- (void)resolutionChange:(SMBCloudSDKPlayerResolution)resolution;

/**
 * @brief 音量改变
 * @param volume 音量
 */
- (void)volumeChange:(NSInteger)volume;

/**
 * @brief 数据获取量改变
 * @param dataSize 数据量
 * @param speed 速度
 */
- (void)dataReceivedChange:(NSString *)dataSize speed:(NSString *)speed;


@end

/**
 * @brief 播放器截图状态回调协议
 *
 */
@protocol SMBCloudSDKPlayerSnapshotDelegate <NSObject>

/**
 * @brief 成功截图
 * @param paths 截图目标路径
 *
 */
- (void)didSaveSnapshotToPaths:(NSArray<NSString *> *)paths;
/**
 * @brief 截图失败
 * @param error 截图失败原因
 * @see SMBCloudSDKPlayerSnapshotFinishReason
 */
- (void)failedSaveSnapshotWithError:(SMBCloudSDKPlayerSnapshotFinishReason)error;

@end

/**
 * @brief 播放器录像状态回调协议
 *
 */
@protocol SMBCloudSDKPlayerRecordDelegate <NSObject>
/**
 * @brief 录像状态改变
 * @param isRecording 是否正在录像
 *
 */
- (void)recordStatusChange:(BOOL)isRecording;
/**
 * @brief 录像时长改变
 * @param duration 录像时长
 *
 */
- (void)recordDurationChange:(NSTimeInterval)duration;
/**
 * @brief 成功录像
 * @param paths 录像目标路径
 *
 */
- (void)didSaveRecordVideoToPaths:(NSArray<NSString *> *)paths;
/**
 * @brief 录像失败
 * @param error 录像失败原因
 * @see SMBCloudSDKPlayerRecordFinishReason
 *
 */
- (void)failedSaveRecordVideoWithError:(SMBCloudSDKPlayerRecordFinishReason)error;

@end

NS_ASSUME_NONNULL_END
