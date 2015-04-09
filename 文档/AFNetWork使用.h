//
//  AFNetWork使用.h
//  文档
//
//  Created by guohui on 15/4/9.
//  Copyright (c) 2015年 youyibao. All rights reserved.
//

//GET 请求

#import "AFHTTPRequestOperationManager.h"

AFHTTPRequestOperationManager*manager;

manager=[AFHTTPRequestOperationManager manager];

[manager GET:@"http://10.0.182.123/share_1439/neihan.json" parameters:nil success:^(AFHTTPRequestOperation *operation, id responseObject) {
    //responseObject请求好的解析完的数据
    NSLog(@"请求成功~~%@",responseObject);
} failure:^(AFHTTPRequestOperation *operation, NSError *error) {
    NSLog(@"请求失败");
}];


//坑人地方来了，在你设置的前提，默认只支持json格式，text/html都不支持

//对manager进行设置
manager.responseSerializer.acceptableContentTypes=[NSSet setWithObjects:@"text/html",@"application/json", nil];



[manager GET:@"http://10.0.8.8/sns/my/login.php?username=erfangdong&password=123456" parameters:nil success:^(AFHTTPRequestOperation *operation, id responseObject) {
    NSLog(@"外网text地址成功~~~");
} failure:^(AFHTTPRequestOperation *operation, NSError *error) {
    NSLog(@"请求失败原因~~%@",error);
    
}];


//POST 请求


#import "AFHTTPRequestOperationManager.h"

AFHTTPRequestOperationManager*manager;
//POST请求有2种方式，一种是上传参数方式 一种上传表单的方式，所谓表单就是上传文件
manager=[AFHTTPRequestOperationManager manager];
//http://10.0.8.8/sns/my/login.php?username=erfangdong&password=123456


//上传参数的方式

//创建字典
manager.responseSerializer.acceptableContentTypes=[NSSet setWithObjects:@"text/html",@"application/json", nil];
NSDictionary*dic=@{@"username":@"erfangdong",@"password":@"123456"};
[manager POST:@"http://10.0.8.8/sns/my/login.php" parameters:dic success:^(AFHTTPRequestOperation *operation, id responseObject) {
    NSLog(@"请求成功~~%@",responseObject);
} failure:^(AFHTTPRequestOperation *operation, NSError *error) {
    NSLog(@"请求失败~~%@",error);
}];


//上传图片
NSString*token=@"92240m5DM668XHkeMyhWEIkaoNAK5uJjwjY7cHCUZ2v8SuLWlw3J9qLOFUTsMcPXDchRy/mNzgxxRMl6LAOw+/5c1Q";
NSDictionary*dic1=@{@"albumid":@"0",@"pic_title":@"hehe",@"m_auth":token};
[manager POST:@"http://10.0.8.8/sns/my/upload_photo.php" parameters:dic1 constructingBodyWithBlock:^(id<AFMultipartFormData> formData) {
    //设置表单
    UIImage*image=[UIImage imageNamed:@"1.png"];
    
    [formData appendPartWithFileData:UIImagePNGRepresentation(image) name:@"attach" fileName:@"image11.png" mimeType:@"image/png"];
    
} success:^(AFHTTPRequestOperation *operation, id responseObject) {
    NSLog(@"请求成功~~%@",responseObject);
} failure:^(AFHTTPRequestOperation *operation, NSError *error) {
    NSLog(@"请求失败~~%@",error);
}];












