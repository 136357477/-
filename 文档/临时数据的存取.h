//
//  临时数据的存取.h
//  文档
//
//  Created by guohui on 15/4/9.
//  Copyright (c) 2015年 youyibao. All rights reserved.
//
//保存临时数据：
NSUserDefaults *user = [NSUserDefaults standardUserDefaults];
[user setObject:[NSString stringWithFormat:@"%@",[yiShengDic objectForKey:suoShuYYID]] [user setObject:[NSString stringWithFormat:@"%@",[yiShengDic objectForKey:keShiID]] forKey:keShiID];
 [user synchronize]; //必须有否则无数据
 
 
 
// 获得临时存储的数据：
 NSUserDefaults *user = [NSUserDefaults standardUserDefaults];
 NSString *loginName = [user objectForKey:kXMPPmyJID];