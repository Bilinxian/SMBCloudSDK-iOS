//
//  SMBSDKContext.h
//  Pods
//
//  Created by Li Weijian on 2023/5/24.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface SMBSDKContext : NSObject

- (instancetype)init NS_UNAVAILABLE;

/**
 * @brief 获取SMBSDKContext单例
 */
+ (instancetype)shared NS_SWIFT_NAME(shared());

/**
 * @brief SMBSDKContext的初始化设置
 */
- (void)setup;

/**
 * @brief 设置AK/SK认证
 * @discussion 需设置正确的认证信息后才能正常请求
 * @param accessKey 从Web端开发者页面获取的AK
 * @param secretKey 从Web端开发者页面获取的SK
 * @param terminalUUID 终端唯一标识，一般使用系统方法获取手机idfv即可，长度限制1-64个字符，不可全为空格或包含英文逗号(,)。
 */
- (void)setAccessKey:(NSString *)accessKey secretKey:(NSString *)secretKey terminalUUID:(NSString *)terminalUUID
NS_SWIFT_NAME(set(accessKey:secretKey:terminalUUID:));


@end

NS_ASSUME_NONNULL_END
