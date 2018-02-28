//
//  ObjectLife.swift
//  JMLearningSwift
//
//  Created by xserver on 15/4/30.
//  Copyright (c) 2015年 https://github.com/xserver. All rights reserved.
//

import UIKit

class ObjectLife: NSObject {
    
    var name: NSString?
    
    
    override init() {
        name = "overide init"
    }
    
    init(name: NSString) {
        self.name = name
        
    }
    
    init(objectName name: NSString) {
        self.name = name
        
    }
    
    init(_ name: NSString) {
        
    }
}
