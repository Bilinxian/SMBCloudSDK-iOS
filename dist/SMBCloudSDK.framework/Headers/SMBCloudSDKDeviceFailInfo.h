//
//  SMBCloudSDKDeviceFailInfo.h
//  Pods
//
//  Created by chenkairong on 2024/2/22.
//

#import <SMBCloudSDK/SMBCloudSDKDeviceParam.h>

@interface SMBCloudSDKDeviceFailInfo: SMBCloudSDKDeviceParam

/**
 * @brief 失败错误码
 */
@property (nonatomic, assign, readonly) NSInteger errorCode;

- (instancetype)init NS_UNAVAILABLE;

@end
