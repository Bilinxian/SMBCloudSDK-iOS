//
//  SMBCloudSDKPlaybackManagerDefines.h
//  Pods
//
//  Created by Li Weijian on 2023/9/23.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
/**
 *  @brief 回放存储类型
 */
typedef NS_ENUM(NSInteger, SMBCloudSDKStorageType) {
    /** @brief 回放存储类型: 不支持 */
    SMBCloudSDKStorageTypeNotSupport = -1,
    /** @brief 回放存储类型: PTZ回放 */
    SMBCloudSDKStorageTypePTZ = 0,
    /** @brief 回放存储类型: NVR录像回放 */
    SMBCloudSDKStorageTypeNVR = 1,
    /** @brief 回放存储类型: IPC录像回放 */
    SMBCloudSDKStorageTypeIPC = 2,
    /** @brief 回放存储类型: VCS录像回放 */
    SMBCloudSDKStorageTypeVCS = 4,
};


NS_ASSUME_NONNULL_END
