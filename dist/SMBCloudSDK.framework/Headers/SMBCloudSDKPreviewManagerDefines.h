//
//  SMBCloudSDKPreviewManagerDefines.h
//  Pods
//
//  Created by Li Weijian on 2023/9/23.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @brief 语音操作
 */
typedef NS_OPTIONS(NSInteger, SMBCloudSDKVoiceOperation) {
    /** @brief 不支持语音操作 */
    SMBCloudSDKVoiceOperationNone = 1 << 0,
    /** @brief 语音操作: 扬声器*/
    SMBCloudSDKVoiceOperationSpeaker = 1 << 1,
    /** @brief 语音操作: 麦克风*/
    SMBCloudSDKVoiceOperationMicrophone = 1 << 2,
};

/**
 * @brief 八个云台转动的方向
 * @discussion 8个旋转方向(上、右上、右、右下、下、左下、左、左上)
 */
typedef NS_ENUM(NSInteger, SMBCloudSDKPtzRotateDirection) {
    /** @brief 云台转动方向: 向右 */
    SMBCloudSDKPtzRotateDirectionRight = 1,
    /** @brief 云台转动方向: 右下 */
    SMBCloudSDKPtzRotateDirectionRightDown = 2,
    /** @brief 云台转动方向: 向下 */
    SMBCloudSDKPtzRotateDirectionDown = 3,
    /** @brief 云台转动方向: 左下 */
    SMBCloudSDKPtzRotateDirectionLeftDown = 4,
    /** @brief 云台转动方向: 向左 */
    SMBCloudSDKPtzRotateDirectionLeft = 5,
    /** @brief 云台转动方向: 左上 */
    SMBCloudSDKPtzRotateDirectionLeftUp = 6,
    /** @brief 云台转动方向: 向上 */
    SMBCloudSDKPtzRotateDirectionUp = 7,
    /** @brief 云台转动方向: 右上 */
    SMBCloudSDKPtzRotateDirectionRightUp = 8,
};

/**
 * @brief 云台速度
 * @discussion 速度有7档：极慢、慢、略慢、正常、略快、快、极快
 */
typedef NS_ENUM(NSInteger, SMBCloudSDKPtzSpeed) {
    /** @brief 云台转动速度: 极慢 */
    SMBCloudSDKPtzSpeedVeryLow = 1,
    /** @brief 云台转动速度: 慢 */
    SMBCloudSDKPtzSpeedLow = 2,
    /** @brief 云台转动速度: 略慢 */
    SMBCloudSDKPtzSpeedLittleLow = 3,
    /** @brief 云台转动速度: 正常 */
    SMBCloudSDKPtzSpeedNormal = 4,
    /** @brief 云台转动速度: 略快 */
    SMBCloudSDKPtzSpeedLittleFast = 5,
    /** @brief 云台转动速度: 快 */
    SMBCloudSDKPtzSpeedFast = 6,
    /** @brief 云台转动速度: 极快 */
    SMBCloudSDKPtzSpeedVeryFast = 7,
};

/**
 * @brief 云台变倍
 * @discussion 放大/缩小
 */
typedef NS_ENUM(NSInteger, SMBCloudSDKPtzZoom) {
    /** @brief 云台变倍：扩大 */
    SMBCloudSDKPtzZoomIn = 10,
    /** @brief 云台变倍：缩小 */
    SMBCloudSDKPtzZoomOut = 11,
};

/**
 * @brief 云台调焦
 * @discussion 聚焦近处/远处
 */
typedef NS_ENUM(NSInteger, SMBCloudSDKPtzFocus) {
    /** @brief 云台调焦：聚焦近处 */
    SMBCloudSDKPtzFocusNear = 12,
    /** @brief 云台调焦：聚焦远处 */
    SMBCloudSDKPtzFocusFar = 13,
};

/**
 * @brief 云台原点功能
 */
typedef NS_ENUM(NSInteger, SMBCloudSDKPtzHomePositionMode) {
    /** @brief 不支持云台原点功能 */
    SMBCloudSDKPtzHomePositionModeNone = 0,
    /** @brief 云台原点功能：原点固定 */
    SMBCloudSDKPtzHomePositionModeFixed = 1,
    /** @brief 云台原点功能：原点可配置 */
    SMBCloudSDKPtzHomePositionModeConfigurable = 2,
};

/**
 * @brief 镜头镜像类型
 */
typedef NS_ENUM(NSInteger, SMBCloudSDKScreenFlipType) {
    /** @brief 关闭镜头镜像 */
    SMBCloudSDKScreenFlipTypeClose = 0,
    /** @brief 镜头镜像: 左右翻转*/
    SMBCloudSDKScreenFlipTypeLeftAndRight = 1,
    /** @brief 镜头镜像: 上下翻转*/
    SMBCloudSDKScreenFlipTypeUpAndDown = 2,
    /** @brief 镜头镜像: 中心翻转*/
    SMBCloudSDKScreenFlipTypeCentral = 3,
};

/**
 * @brief 画面旋转类型
 */
typedef NS_ENUM(NSInteger, SMBCloudSDKScreenRotateType) {
    /** @brief 关闭画面旋转 */
    SMBCloudSDKScreenRotateTypeClose = 0,
    /** @brief 画面旋转: 逆时针180度*/
    SMBCloudSDKScreenRotateTypeAntiClockwise180 = 1,
    /** @brief 画面旋转: 顺时针90度*/
    SMBCloudSDKScreenRotateTypeClockwise90 = 2,
    /** @brief 画面旋转: 逆时针90度*/
    SMBCloudSDKScreenRotateTypeAntiClockwise90 = 3,
};

/*
 *  @brief 鱼眼设备支持的物理安装模式
 */
typedef NSString *SMBCloudSDKFishEyeSupportInstallMode NS_STRING_ENUM;
/** @brief 安装模式：顶装**/
FOUNDATION_EXPORT SMBCloudSDKFishEyeSupportInstallMode const SMBCloudSDKFishEyeSupportInstallModeTop;
/** @brief 安装模式：壁装**/
FOUNDATION_EXPORT SMBCloudSDKFishEyeSupportInstallMode const SMBCloudSDKFishEyeSupportInstallModeWall;

/**
 *  @brief 鱼眼设备输出的画面类型
 */
typedef NSString *SMBCloudSDKFishEyeVideoType NS_STRING_ENUM;
/** @brief 画面类型：圆形 **/
FOUNDATION_EXPORT SMBCloudSDKFishEyeVideoType const SMBCloudSDKFishEyeVideoTypeCircle;
/** @brief 画面类型：非完整圆形，画面上下被裁剪**/
FOUNDATION_EXPORT SMBCloudSDKFishEyeVideoType const SMBCloudSDKFishEyeVideoTypeCutUpDown;

/**
 * @brief 扬声器的输出设备类型
 */
typedef NS_OPTIONS(NSInteger, SMBCloudSDKSpeakerOutputDeviceType) {
    /** @brief 不支持 **/
    SMBCloudSDKSpeakerOutputDeviceTypeUnsupport = 1 << 0,
    /** @brief 外接扬声器 **/
    SMBCloudSDKSpeakerOutputDeviceTypeLineOut = 1 << 1,
    /** @brief 内置扬声器 **/
    SMBCloudSDKSpeakerOutputDeviceTypeSpeakerOut = 1 << 2,
    /** @brief 自动**/
    SMBCloudSDKSpeakerOutputDeviceTypeAuto = 1 << 3,
};

/**
 * @brief 通道能力集
 */
typedef NS_OPTIONS(NSInteger, SMBCloudSDKChannelCapability) {
    /** @brief 不支持 **/
    SMBCloudSDKChannelCapabilityUnsupport = 0,
    /** @brief 鱼眼 **/
    SMBCloudSDKChannelCapabilitySupportFishEye = 1 << 3,
    /** @brief 预置点 **/
    SMBCloudSDKChannelCapabilitySupportPreset = 1 << 11,
    /** @brief 云台复位 **/
    SMBCloudSDKChannelCapabilitySupportManualCalibrate = 1 << 14,
    /** @brief 镜头遮蔽 **/
    SMBCloudSDKChannelCapabilitySupportLensMask = 1 << 15,
    /** @brief 旧版云台 **/
    SMBCloudSDKChannelCapabilitySupportMotor = 1 << 16,
    /** @brief 画面旋转 **/
    SMBCloudSDKChannelCapabilitySupportScreenRotate = 1 << 17,
    /** @brief 镜头翻转 **/
    SMBCloudSDKChannelCapabilitySupportScreenFlip = 1 << 18,
    /** @brief 云台控制 **/
    SMBCloudSDKChannelCapabilitySupportPtz = 1 << 24,
};

/**
 * @brief 声光报警
 */
typedef NS_OPTIONS(NSInteger, SMBCloudSDKMsgAlarmType) {
    /** @brief 不支持 **/
    SMBCloudSDKMsgAlarmTypeUnsupport = 1 << 0,
    /** @brief 声音报警 **/
    SMBCloudSDKMsgAlarmTypeSound = 1 << 1,
    /** @brief 光报警 **/
    SMBCloudSDKMsgAlarmTypeLight = 1 << 2,
};

/**
 *  @brief 光报警类型
 */
typedef NSString *SMBCloudSDKMsgAlarmLightType NS_STRING_ENUM;
/** @brief 光报警类型：闪烁**/
FOUNDATION_EXPORT SMBCloudSDKMsgAlarmLightType const SMBCloudSDKMsgAlarmLightTypeBlink;
/** @brief 光报警类型：常亮**/
FOUNDATION_EXPORT SMBCloudSDKMsgAlarmLightType const SMBCloudSDKMsgAlarmLightTypeOn;


NS_ASSUME_NONNULL_END
