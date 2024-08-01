//
//  SMBCloudSDKPlaybackID.h
//  Pods
//
//  Created by Li Weijian on 2023/9/24.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @brief 设备回放ID，保存设备ID和存储ID
 *
 */
@interface SMBCloudSDKPlaybackID : NSObject

/**@brief 设备ID**/
@property (nonatomic, copy, readonly) NSString *deviceID;
/**@brief 存储ID**/
@property (nonatomic, copy, readonly) NSString *storageID;

- (instancetype)init NS_UNAVAILABLE;

/**
 * @brief SMBCloudSDKPlaybackID初始化方法
 * @param deviceID 设备ID
 * @param storageID 存储ID
 */
- (instancetype)initForDevice:(NSString *)deviceID
                    storageID:(NSString *)storageID;

@end

NS_ASSUME_NONNULL_END
