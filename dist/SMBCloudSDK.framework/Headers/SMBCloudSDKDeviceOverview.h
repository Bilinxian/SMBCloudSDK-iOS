//
//  SMBCloudSDKDeviceOverview.h
//  Pods
//
//  Created by Li Weijian on 2024/1/17.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @brief 分组设备数量信息
*/
@interface SMBCloudSDKDeviceOverview: NSObject

- (instancetype)init NS_UNAVAILABLE;

/**
 * @brief 设备总数
*/
@property (nonatomic, assign, readonly) NSInteger totalDevNum;
/**
 * @brief 在线设备总数
*/
@property (nonatomic, assign, readonly) NSInteger totalDevOnlineNum;

@end

NS_ASSUME_NONNULL_END
