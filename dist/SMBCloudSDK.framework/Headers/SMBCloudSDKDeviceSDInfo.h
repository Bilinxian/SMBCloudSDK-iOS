//
//  SMBCloudSDKDeviceSDInfo.h
//  Pods
//
//  Created by chenkairong on 2024/2/22.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @brief SD卡读写状态
 */
typedef NS_ENUM(NSUInteger, SMBCloudSDKDeviceSDPermission) {
    /** @brief SD卡读写状态：可读写 */
    SMBCloudSDKDeviceSDPermissionReadWrite = 0,
    /** @brief SD卡读写状态：只读 */
    SMBCloudSDKDeviceSDPermissionReadOnly = 1,
    /** @brief SD卡读写状态：只写 */
    SMBCloudSDKDeviceSDPermissionWriteOnly = 2,
};

/**
 * @brief SD卡状态
 */
typedef NS_ENUM(NSUInteger, SMBCloudSDKDeviceSDStatus) {
    /** @brief SD卡状态：无SD卡 */
    SMBCloudSDKDeviceSDStatusNone = 0,
    /** @brief SD卡状态：未初始化 */
    SMBCloudSDKDeviceSDStatusUnFormatted = 1,
    /** @brief SD卡状态：正常 */
    SMBCloudSDKDeviceSDStatusNormal = 2,
    /** @brief SD卡状态：空间不足 */
    SMBCloudSDKDeviceSDStatusInsufficient = 3,
};

/**
 * @brief SD卡信息结构体
 */

@interface SMBCloudSDKDeviceSDInfo: NSObject

/**
 * @brief SD卡索引值
 */
@property (nonatomic, assign, readonly) NSInteger index;

/**
 * @brief 总剩余容量
 */
@property (nonatomic, copy, readonly) NSString *freeSpace;

/**
 * @brief 总容量
 */
@property (nonatomic, copy, readonly) NSString *totalSpace;

/**
 * @brief SD卡读写状态
 */
@property (nonatomic, assign, readonly) SMBCloudSDKDeviceSDPermission permission;

/**
 * @brief SD卡状态
 */
@property (nonatomic, assign, readonly) SMBCloudSDKDeviceSDStatus status;

/**
 * @brief 录像开始时间，UNIX时间戳，精确到秒
 */
@property (nonatomic, assign, readonly) NSTimeInterval recordStartTime;

/**
 * @brief 已录制视频的时长，单位为秒
 */
@property (nonatomic, assign, readonly) NSInteger recordDuration;

/**
 * @brief 已录制时长描述（天/时/分）
 */
@property (nonatomic, copy, readonly) NSString *recordDurationDescription;


- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
