//
//  SMBCloudSDKDeviceAddNVRChannelInfo.h
//  SMBCloudSDK
//
//  Created by qinshiji on 2024/2/22.
//

#import <Foundation/Foundation.h>
#import <SMBCloudSDK/SMBCloudSDKError.h>
#import <SMBCloudSDK/SMBCloudSDKDeviceAddEnumDefines.h>

NS_ASSUME_NONNULL_BEGIN

// MARK: - SMBCloudSDKNotAddedIPCInfo -
/**
 * @brief 局域网下未被添加的IPC信息
*/
@interface SMBCloudSDKNotAddedIPCInfo: NSObject <NSCopying>

- (instancetype)init NS_UNAVAILABLE;

/**
 * @brief 设备唯一ID
*/
@property (nonatomic, readonly, copy) NSString *uuid;

/**
 * @brief 设备名称
*/
@property (nonatomic, readonly, copy) NSString *name;

/**
 * @brief 设备IP
*/
@property (nonatomic, readonly, copy) NSString *ip;

/**
 * @brief 设备端口
*/
@property (nonatomic, readonly, copy) NSString *port;

/**
 * @brief 连接协议。
*/
@property (nonatomic, readonly, copy) NSString *connectProtocol;

/**
 * @brief IPC激活状态
*/
@property (nonatomic, readonly) SMBCloudSDKDeviceActivateType activateStatus;

@end

// MARK: - SMBCloudSDKIPCToAddParam -
/**
 * @brief 局域网下添加NVR通道的IPC参数信息
*/
@interface SMBCloudSDKIPCToAddParam : NSObject

/**
 * @brief 待添加IPC的信息
*/
@property (nonatomic, copy) SMBCloudSDKNotAddedIPCInfo *ipcInfo;

/**
 * @brief 登录用户名。对于未激活或者没有密码的IPC，可直接传空值
*/
@property (nonatomic, nullable, copy) NSString *username;

/**
 * @brief 登录密码。对于未激活或者没有密码的IPC，可直接传空值
*/
@property (nonatomic, nullable, copy) NSString *password;

@end

// MARK: - SMBCloudSDKAddChannelIPCResult -
@interface SMBCloudSDKAddChannelIPCResult : NSObject

- (instancetype)init NS_UNAVAILABLE;
/**
 * @brief 设备唯一ID。可通过该属性与SMBSDKNotAddedIPCInfo中的uuid匹配对应设备
*/
@property (nonatomic, readonly, copy) NSString *uuid;
/**
 * @brief 设备添加结果的错误信息
*/
@property (nonatomic, readonly, copy) SMBCloudSDKError *error;

@end

NS_ASSUME_NONNULL_END
