//
//  SMBCloudSDKPlaybackParams.h
//  Pods
//
//  Created by Li Weijian on 2023/9/24.
//

#import <Foundation/Foundation.h>
#import <SMBCloudSDK/SMBCloudSDKPlaybackManagerDefines.h>

NS_ASSUME_NONNULL_BEGIN
/**
 * @brief 设备回放参数
 *
 */
@interface SMBCloudSDKPlaybackParams : NSObject

/** @brief 客户端ID */
@property (nonatomic, readonly) NSInteger clientID;
/** @brief 回放类型 */
@property (nonatomic, readonly, copy) NSArray<NSNumber *> *eventTypes;
/** @brief 是否不包括回放类型 */
@property (nonatomic, readonly) BOOL isEventsExcluded;
/** @brief 存储ID */
@property (nonatomic, copy) NSString *storageID;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithClientID:(NSInteger)clientID
                     eventTypes:(NSArray<NSNumber *> *)eventTypes
               isEventsExcluded:(BOOL)isEventsExcluded
                      storageID:(NSString *)storageID;

@end

NS_ASSUME_NONNULL_END
