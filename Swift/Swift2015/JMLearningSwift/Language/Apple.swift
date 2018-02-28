//
//  Apple.swift
//  JMLearningSwift
//
//  Created by xserver on 15/4/30.
//  Copyright (c) 2015年 https://github.com/xserver. All rights reserved.
//

import UIKit

enum Fruit {
    case Apple
    case Banana
}

class Apple: NSObject {
    
    var name: NSString
    
    init(name: NSString) {
        self.name = name
        print(self.name, terminator: "")
    }
    
    func say() {
        print("haha \(self.name).")
    }
}
