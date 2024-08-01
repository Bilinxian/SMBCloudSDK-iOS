//
//  SMBCloudSDKDeviceBindStatusInfo.h
//  Pods
//
//  Created by litao on 2024/2/28.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @brief 设备绑定状态信息对象结构
 */
@interface SMBCloudSDKDeviceBindStatusInfo : NSObject

- (instancetype)init NS_UNAVAILABLE;

/**
 * @brief 设备MAC
 */
@property (nonatomic, copy, readonly) NSString *mac;

/**
 * @brief 是否被绑定
 */
@property (nonatomic, assign, readonly) BOOL isBind;

@end

NS_ASSUME_NONNULL_END
