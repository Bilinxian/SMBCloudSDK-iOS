//
//  SMBCloudSDKError.h
//  Pods
//
//  Created by daiwj5 on 2023/9/20.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface SMBCloudSDKError : NSObject
/**
 * @brief 错误码，存在请求成功，但错误码不为0的情况。不建议直接通过判断错误是否等于0来决定请求是否成功。
 *
 */
@property (nonatomic, assign, readonly) NSInteger code;
/**
 * @brief 请求是否成功
 *
 */
@property (nonatomic, assign, readonly) BOOL isSuccess;
/**
 * @brief 错误信息
 *
 */
@property (nonatomic, copy, readonly, nullable) NSString *message;


// MARK: - init
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
