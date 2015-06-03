# 为它写一个初始化的方法，接受散列表和数组嵌套的结构

class Tree
  attr_accessor :children, :node_name
  
  def initialize(name, children)
    @children = children
    @name = name
  end                    

  def initialize(tree)
    tree.each do |key, value|
      @node_name = key
      @children = value.map { 
        |(key, value)| 
        Tree.new(key => value)  # 递归
      }
    end
  end
                      
  def visit_all(&block)
    visit &block
    children.each { |c| c.visit_all &block}
  end
                      
  def visit(&block)
    block.call self
  end
end


ruby_tree = Tree.new(
    {'grandpa' => {
        'dad' => {'child 1' => {}, 'child 2' => {}}, 
      'uncle' => {'child 3' => {}, 'child 4' => {}} 
      }
    })

ruby_tree.visit_all {|node| puts node.node_name}
# ruby_tree.visit {|node| puts node.node_name}

