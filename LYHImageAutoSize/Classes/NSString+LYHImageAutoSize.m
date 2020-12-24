//
//  NSString+LYHImageAutoSize.m
//  LYHImageAutoSizeExample
//
//  Created by Lucas on 09/28/2020.
//  Copyright (c) 2020 Lucas. All rights reserved.
//  http://git.swste.com/lucas/LYHImageAutoSize

#import "NSString+LYHImageAutoSize.h"
#import <CommonCrypto/CommonDigest.h>

@implementation NSString (LYHImageAutoSize)
-(NSString *)sizeKeyName{
    NSString *keyName = [NSString stringWithFormat:@"sizeKeyName:%@",self];
    return keyName.md5String;
}
-(NSString *)reloadKeyName{
    NSString *keyName = [NSString stringWithFormat:@"reloadKeyName:%@",self];
    return keyName.md5String;
}
-(NSString *)md5String{
    const char *value = [self UTF8String];
    unsigned char outputBuffer[CC_MD5_DIGEST_LENGTH];
    CC_MD5(value, (CC_LONG)strlen(value), outputBuffer);
    NSMutableString *outputString = [[NSMutableString alloc] initWithCapacity:CC_MD5_DIGEST_LENGTH * 2];
    for(NSInteger count = 0; count < CC_MD5_DIGEST_LENGTH; count++){
        [outputString appendFormat:@"%02x",outputBuffer[count]];
    }
    return outputString;
}
@end
