//
//  LLDebugTool.h
//
//  Copyright (c) 2018 LLDebugTool Software Foundation (https://github.com/HDB-Li/LLDebugTool)
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in all
//  copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//  SOFTWARE.

#import <Foundation/Foundation.h>
#import "LLConfig.h"
#import "MonkeyPaws.h"

#ifndef LLSharedDebugTool
#define LLSharedDebugTool [LLDebugTool sharedTool]
#endif



@class LLWindow;

/**
 Control whether DebugTool is started.
 */
@interface LLDebugTool : NSObject

/**
 Suspension ball window.
 */
@property (nonatomic , strong , readonly , nonnull) LLWindow *window;

/**
 Singleton to control debugTool.
 
 @return Singleton
 */
+ (instancetype _Nonnull)sharedTool;

/**
 Start working.
 */
- (void)startWorking;

/**
 Stop working.
 */
- (void)stopWorking;

/**
 Whether working or not.
 */
@property (nonatomic , assign , readonly) BOOL isWorking;

/**
 LLDebugTool's version.
 */
@property (nonatomic , copy , readonly , nonnull) NSString * version;

/**
 Whether is Beta.
 */
@property (nonatomic , assign , readonly) BOOL isBetaVersion;

/**
 Automatic open debug view controller with index.
 */
- (void)showDebugViewControllerWithIndex:(NSInteger)index;

/**
 Print and save a log model with infos.
 
 @param file File name.
 @param function Function name.
 @param lineNo Line number.
 @param level Log level.
 @param onEvent Event,can filter by this.
 @param message Message.
 */
- (void)logInFile:(NSString *_Nullable)file function:(NSString *_Nullable)function lineNo:(NSInteger)lineNo level:(LLConfigLogLevel)level onEvent:(NSString *_Nullable)onEvent message:(NSString *_Nullable)message;


/**
 保存已经发送的报文
 */
@property (nonatomic,strong,nonnull) NSMutableDictionary *cmd_seq_dict ;
@property (nonatomic,strong,nonnull) NSMutableString *cmd_to_send ;
@property (nonatomic,strong,nonnull) NSMutableString *cmd_to_receive ;
typedef void (^PrivateNetworkBlock)(NSString *_Nullable);
@property (nonatomic, copy,nonnull) PrivateNetworkBlock sendBlock;
@property (nonatomic, copy,nonnull) PrivateNetworkBlock receiveBlock;


- (void)addPrivateNetworkSendBlock:(void(^_Nullable)(NSString *_Nullable command))block;
- (void)addPrivateNetworkReceiveBlock:(void(^_Nullable)(NSString *_Nullable command))block;
- (void)dealWithResponseData:(NSString *_Nullable)command response:(NSData *_Nullable)response request:(NSData *_Nullable)request date:(NSDate *_Nullable)date;
- (void)dealWithHttpResponseData:(NSString *_Nullable)command response:(NSData *_Nullable)response request:(NSData *_Nullable)request date:(NSDate *_Nullable)date ;

/**
 高内存操作线程
 */
@property (nonatomic, strong,nullable) NSThread *memoryThread;


/**
 monkey定时器
 */
@property(nonatomic,strong,nullable)NSTimer *iosMonkeyTimer;
@property(nonatomic,strong,nullable)NSTimer *cocosMonkeyTimer;

/**
 monkey开始时间
 */
@property(nonatomic,strong,nullable)NSDate *startDate;

/**
更多功能的 switch开关
 */

- (void)saveMockSwitch:(BOOL)on;

- (BOOL)mockSwitch;

- (void)saveLowNetworkSwitch:(BOOL)on;

- (BOOL)lowNetworkSwitch;

- (void)saveLowMemorySwitch:(BOOL)on;

- (BOOL)lowMemorySwitch;

- (BOOL)iosMonkeySwitch;

- (void)saveIOSMonkeySwitch:(BOOL)on;

- (BOOL)cocosMonkeySwitch;

- (void)saveCocosMonkeySwitch:(BOOL)on;

- (BOOL)privateNetworkSwitch ;

- (void)savePrivateNetworkSwitch:(BOOL)on ;
/**
 丢包率相关api
 */
- (BOOL)isPacketLoss:(float)increase ;
- (void)setPacketCount:(float)packetCount ;

/**
 截图api
*/
- (void)simulateDirectTakeScreenshot:(NSString *_Nullable)imagePath ;

/**
 获取日志api
 */
- (NSMutableArray *_Nullable)copySourceFileArr:(NSArray*_Nullable)sourceFileArr toDestDir:(NSString*_Nullable)destDir;

/**
 monkey 小手
 */
//@property(strong ,nonatomic) id paws ;
@property (strong, nonatomic) MonkeyPaws *paws;


/**
 获取CocosCreator控件树
 */
typedef NSDictionary* (^CocosCreatorTree)(void) ;
@property (nonatomic, copy,nonnull) CocosCreatorTree ccTree;
- (void)addCocosCreatorTree:(CocosCreatorTree)ccTree;

/**
 上传日志接口
 */
typedef void (^UploadLog)(void) ;
@property (nonatomic, copy,nonnull) UploadLog uploadLog;
- (void)addUploadLog:(UploadLog)uploadLog;
@end
