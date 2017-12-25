<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
	<head>
		<style>
			body, table{font-family: 微软雅黑; font-size: 10pt}
			table{border-collapse: collapse; border: solid gray; border-width: 2px 0 2px 0;}
			th{border: 1px solid gray; padding: 4px; background-color: #DDD;}
			td{border: 1px solid gray; padding: 4px;}
			tr:nth-child(2n){background-color: #f8f8f8;}
		</style>
	</head>
	<body>
		<div>
			<div><span style="font-size: medium;">&nbsp; &nbsp; &nbsp; 一般来说，<span style="color: rgb(255, 0, 0);">类的私有成员只能在类的内部访问，类外的函数是不能访问它们</span>的。</span><span style="font-size: medium; ">但是，可以<span style="color: rgb(255, 0, 0);">将一个函数定义为类的友元函数，这时该函数就可以访问该类的私有成员</span>了。</span><span style="font-size: medium; ">同时，也可以<span style="color: rgb(255, 0, 0);">把另一个类B定义为本类A的友元类，这样B类就可以访问A类的任何成员</span>了</span>
			</div>
		</div>
		<div><span style="font-size: medium;"><br /></span>
		</div>
		<div><span style="font-size: medium;"><span style="color: #ff0000">***************</span>函数传参存在隐士转换，形参必须声明const才能真正绑定</span>
		</div>
		<div><span style="font-size: medium;">
			<table style="table-layout: fixed; word-break: break-all; width: 100%; empty-cells: show; margin-left: 0px; background-color:#EAF2D3;">
				<tbody>
					<tr>
						<td>
							<div>1）当函数的形参类型是const类型时，可以通过const类型的实参调用函数，也可以用非const类型的实参调用函数。
							</div>
							<div><br />
							</div>
							<div>2）当函数的形参类型是非const类型时，只能用非const类型的实参调用函数。
							</div>
							<div><br />
							</div>
							<div>综上两点可以看出，在不需要修改实参的情况下，函数的形参类型声明为const类型时，初始化的限制条件会相对放松些。所以有一种情况应当引起重视，就是应该吧不需要修改的应用形参定义为const引用。因为普通的非const应用会限制函数的应用，比如，这样的形参不能用const对象初始化，不能用字面值或产生右值的表达式初始化。
							</div>
						</td>
					</tr>
				</tbody>
			</table></span>
		</div>
		<div><span style="font-size: 12pt"><br /></span>
		</div>
		<div><span style="font-size: 24pt"><strong>友元之非成员函数:</strong></span>
		</div>
		<div><span style="font-size: medium; "><br /></span>
		</div>
		<div><span style="font-size: medium; "><br /></span>
		</div>
		<div><span style="font-size: medium; ">&nbsp; &nbsp; &nbsp; &nbsp;在类的定义中用<span style="color: #ff0000"><strong>friend</strong></span>声明了一个外部函数或其他类的成员函数<span style="color: #ff0000">(public和private均可）</span>后，这个外部函数称为类的友元函数。</span>
		</div>
		<div><span style="font-size: medium; "><br /></span>
		</div>
		<div>
			<div><span style="font-size: 12pt; color: #ffff00; background-color: rgb(153, 51, 102);">友元函数声明的基本格式为：</span>
			</div>
			<div>
				<div><span style="font-size: 12pt; background-color: rgb(255, 255, 0);">friend 函数原型;</span>
				</div>
				<div style="font-size: medium; "><span style="color: #ff0000"><strong>友元函数中可访问类的private成员</strong></span>
				</div>
			</div>
		</div>
		<div>
			<div><span style="font-size: 10pt">&nbsp; &nbsp; &nbsp;将类比作一个家庭，类的private成员相当于家庭的秘密，一般的外人是不允许探听这些秘密的，只有friend（朋友）才有能力探听这些秘密。</span>
			</div>
		</div>
		<div><span style="font-size: medium;">
			<table style="table-layout: fixed; word-break: break-all; width: 100%; empty-cells: show; margin-left: 0px; background-color: #EAF2D3">
				<tbody>
					<tr>
						<td>
							<div>
								<div><span style="font-size: 12pt">#include &lt;iostream&gt;</span>
								</div>
								<div><span style="font-size: 12pt">#include&lt;math.h&gt;</span>
								</div>
								<div><span style="font-size: 12pt">using namespace std;</span>
								</div>
								<div><span style="font-size: 12pt">class point</span>
								</div>
								<div><span style="font-size: 12pt">{</span>
								</div>
								<div><span style="font-size: 12pt">&nbsp; &nbsp; &nbsp; &nbsp; private:</span>
								</div>
								<div><span style="font-size: 12pt">&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; int _x;</span>
								</div>
								<div><span style="font-size: 12pt">&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; int _y;</span>
								</div>
								<div><span style="font-size: 12pt">&nbsp; &nbsp; &nbsp; &nbsp; public:</span>
								</div>
								<div><span style="font-size: 12pt">&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; point(int x=0,int y=0):_x(x),_y(y)</span>
								</div>
								<div><span style="font-size: 12pt">&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; {</span>
								</div>
								<div><span style="font-size: 12pt">&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; cout&lt;&lt;&quot;point(int,int)&quot;&lt;&lt;endl;</span>
								</div>
								<div><span style="font-size: 12pt">&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; }</span>
								</div>
								<div><span style="font-size: 12pt">&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; void print()</span>
								</div>
								<div><span style="font-size: 12pt">&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; {</span>
								</div>
								<div><span style="font-size: 12pt">&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; cout&lt;&lt;&quot;(&quot;&lt;&lt;_x&lt;&lt;&quot;,&quot;&lt;&lt;_y&lt;&lt;&quot;)&quot;&lt;&lt;endl;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span>
								</div>
								<div><span style="font-size: 12pt">&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; }</span>
								</div>
								<div><span style="font-size: 12pt">&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;<span style="color: #ff0000"><strong> &nbsp; &nbsp; friend float dis(const point &amp; a1,const point &amp; a2);</strong></span></span>
								</div>
								<div><span style="font-size: 12pt">};</span>
								</div>
							</div>
						</td>
						<td>
							<div><span style="font-size: 12pt"><span style="color: #ff0000"><strong>float dis(const point&amp; a1,const point&amp; a2)</strong></span></span>
							</div>
							<div><span style="font-size: 12pt">{</span>
							</div>
							<div><span style="font-size: 12pt">&nbsp; &nbsp; &nbsp; &nbsp; return sqrt((a1._x-a2._x)*(a1._x-a2._x)+</span>
							</div>
							<div><span style="font-size: 12pt">&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; (a1._y-a2._y)*(a1._y-a2._y));</span>
							</div>
							<div><span style="font-size: 12pt">}</span>
							</div>
							<div><span style="font-size: 12pt">int main()</span>
							</div>
							<div><span style="font-size: 12pt">{</span>
							</div>
							<div><span style="font-size: 12pt">&nbsp; &nbsp; &nbsp; &nbsp; point a1(1,2);</span>
							</div>
							<div><span style="font-size: 12pt">&nbsp; &nbsp; &nbsp; &nbsp; point a2(4,6);</span>
							</div>
							<div><span style="font-size: 12pt">&nbsp; &nbsp; &nbsp; &nbsp; cout&lt;&lt;&quot;dis=&quot;&lt;&lt;dis(a1,a2)&lt;&lt;endl;</span>
							</div>
							<div><span style="font-size: 12pt">&nbsp; &nbsp; &nbsp; &nbsp; return 0;</span>
							</div>
							<div><span style="font-size: 12pt">}</span>
							</div>
							<div><span style="font-size: 12pt"><img src="data:image/png;base64,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" /></span>
							</div>
						</td>
					</tr>
				</tbody>
			</table></span>
		</div>
		<div><span style="font-size: medium;"><br /></span>
		</div>
		<div><span style="font-size: 12pt"><br /></span>
		</div>
		<div><span style="font-size: 12pt"><br /></span>
		</div>
		<div><span style="font-size: 24pt"><strong>友元之成员函数:</strong></span>
		</div>
		<div>
			<div style="font-size: medium; ">A类的成员函数<span style="color: #ff0000">(公有)</span>作为B类的友元函数时，必须先定义A类，而不仅仅是声明它。
			</div>
			<div>
				<div><span style="color: #ff0000; font-size: medium; ">注意</span><span style="font-size: 12pt">：</span><span style="font-size: 10pt">将其他类的成员函数申明为本类的友元函数后，该友元函数并不能变成本类的成员函数。也就是说，朋友并不能变成家人。</span>
				</div>
				<div style="font-size: medium; ">
					<table style="table-layout: fixed; word-break: break-all; width: 100%; empty-cells: show; margin-left: 0px; background-color:#EAF2D3;">
						<tbody>
							<tr>
								<td>
									<div>#include &lt;iostream&gt;
									</div>
									<div>#include&lt;math.h&gt;
									</div>
									<div>using namespace std;
									</div>
									<div><strong style="color: rgb(255, 0, 0); ">class point; &nbsp;</strong><span style="font-size: 12pt; color: #ffff00; background-color: rgb(153, 51, 102);"> //前向声明</span>
									</div>
									<div>class line
									</div>
									<div>{
									</div>
									<div>&nbsp; &nbsp; &nbsp;<span style="color: #ff0000"><strong style="background-color: rgb(0, 255, 255);"> &nbsp; public:</strong></span>
									</div>
									<div>&nbsp; &nbsp; &nbsp; &nbsp;<span style="color: #ff0000"> float dis(const point &amp;a1,const point &amp;a2);</span>
									</div>
									<div>};
									</div>
									<div>class point
									</div>
									<div>{
									</div>
									<div>&nbsp; &nbsp; &nbsp; &nbsp; private:
									</div>
									<div>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; int _x;
									</div>
									<div>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; int _y;
									</div>
									<div>&nbsp; &nbsp; &nbsp; &nbsp; public:
									</div>
									<div>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; point(int x=0,int y=0):_x(x),_y(y)&nbsp; &nbsp; &nbsp; &nbsp; 
									</div>
									<div>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; {
									</div>
									<div>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; cout&lt;&lt;&quot;point(int,int)&quot;&lt;&lt;endl;
									</div>
									<div>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; }
									</div>
									<div>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; void print()
									</div>
									<div>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; {
									</div>
									<div>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; cout&lt;&lt;&quot;(&quot;&lt;&lt;_x&lt;&lt;&quot;,&quot;&lt;&lt;_y&lt;&lt;&quot;)&quot;&lt;&lt;endl;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; 
									</div>
									<div>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; }
									</div>
									<div><span style="color: #ff0000"><strong>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; friend float line::dis(const point &amp;a1,const point &amp;a2);</strong></span>
									</div>
									<div>};
									</div>
								</td>
								<td>
									<div><span style="color: #ff0000"><strong>float line::dis(const point &amp;a1,const point &amp;a2)</strong></span>
									</div>
									<div>{
									</div>
									<div>&nbsp; &nbsp; &nbsp; &nbsp; return sqrt((a1._x-a2._x)*(a1._x-a2._x)+
									</div>
									<div>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; (a1._y-a2._y)*(a1._y-a2._y));
									</div>
									<div>}
									</div>
									<div>int main()
									</div>
									<div>{
									</div>
									<div>&nbsp; &nbsp; &nbsp; &nbsp; point a1(1,2);
									</div>
									<div>&nbsp; &nbsp; &nbsp; &nbsp; point a2(4,6);
									</div>
									<div>&nbsp; &nbsp; &nbsp; &nbsp; line aa;
									</div>
									<div>&nbsp; &nbsp; &nbsp; &nbsp; cout&lt;&lt;&quot;dis=&quot;&lt;&lt;aa.dis(a1,a2)&lt;&lt;endl;
									</div>
									<div>}
									</div>
									<div><img src="data:image/png;base64,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" />
									</div>
								</td>
							</tr>
						</tbody>
					</table>
				</div>
			</div>
		</div>
		<div><span style="font-size: 12pt"><br /></span>
		</div>
		<div><span style="font-size: medium;"><br /></span>
		</div>
		<div><span style="font-size: medium;"><br /></span>
		</div>
		<div><span style="font-size: 24pt"><strong>友元函数的重载:</strong></span>
		</div>
		<div><span style="font-size: medium;">
			<div><span style="color: #ff0000">要想使得一组重载函数全部成为类的友元，必须一一声明</span>，否则只有匹配的那个函数会成为类的友元，编译器仍将其他的当成普通函数来处理。
			</div>
			<div>
				<table style="table-layout: fixed; word-break: break-all; width: 60%; empty-cells: show; margin-left: 0px; background-color:#EAF2D3;">
					<tbody>
						<tr>
							<td>
								<div>class Exp
								</div>
								<div>{
								</div>
								<div>&nbsp; &nbsp; &nbsp;public:
								</div>
								<div><span style="color: #ff0000"><strong>&nbsp; &nbsp; &nbsp;firend void test(int);&nbsp; &nbsp;</strong></span> &nbsp; &nbsp;&nbsp; 
								</div>
								<div>};
								</div>
								<div>void test();
								</div>
								<div><span style="color: #ff0000"><strong>void test(int);</strong></span>
								</div>
								<div>void test(double);
								</div>
							</td>
						</tr>
					</tbody>
				</table>
			</div></span>
		</div>
		<div><span style="font-size: medium;"><br /></span>
		</div>
		<div><span style="font-size: medium;"><br /></span>
		</div>
		<div><span style="font-size: 24pt"><strong>友元类:</strong></span>
		</div>
		<div>
			<div style="font-size: medium; ">类A作为类B的友元时，类A称为友元类。A中的所有成员函数都是B的友元函数，都可以访问B中的所有成员。
			</div>
			<div>
				<div style="font-size: medium; ">A可以在B的public部分或private部分进行声明，方法如下：
				</div>
				<div style="font-size: medium; "><br />
				</div>
				<div>
					<div><span style="font-size: 12pt; background-color: rgb(255, 255, 0);">friend [class]&lt;类名&gt;; //友元类类名</span>
					</div>
					<div style="font-size: medium; "><br />
					</div>
				</div>
			</div>
		</div>
		<div><span style="font-size: medium;">
			<table style="table-layout: fixed; word-break: break-all; width: 100%; empty-cells: show; margin-left: 0px; background-color:#EAF2D3;">
				<tbody>
					<tr>
						<td>
							<div>#include &lt;iostream&gt;
							</div>
							<div>#include&lt;math.h&gt;
							</div>
							<div>using namespace std;
							</div>
							<div>class point;&nbsp;&nbsp; //前向声明
							</div>
							<div>class line
							</div>
							<div>{
							</div>
							<div>&nbsp; &nbsp; &nbsp; &nbsp;<span style="color: #ff0000; font-size: 12pt"><strong> public:</strong></span>
							</div>
							<div>&nbsp; &nbsp; &nbsp; &nbsp; <span style="font-size: 12pt; color: #ffff00; background-color: rgb(153, 51, 102);">//让类的每一个成员函数都成为point类的友元函数</span>
							</div>
							<div>&nbsp; &nbsp; &nbsp;<span style="color: #ff0000"> &nbsp; float dis(const point &amp;a1,const point &amp;a2);</span>
							</div>
							<div><span style="color: #ff0000">&nbsp; &nbsp; &nbsp; &nbsp; void set(point &amp;p1,int x,int y);</span>
							</div>
							<div>};
							</div>
							<div>class point
							</div>
							<div>{
							</div>
							<div>&nbsp; &nbsp; &nbsp; &nbsp; private:
							</div>
							<div>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; int _x;
							</div>
							<div>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; int _y;
							</div>
							<div>&nbsp; &nbsp; &nbsp; &nbsp; public:
							</div>
							<div>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; point(int x=0,int y=0):_x(x),_y(y)
							</div>
							<div>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; {
							</div>
							<div>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; cout&lt;&lt;&quot;point(int,int)&quot;&lt;&lt;endl;
							</div>
							<div>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; }
							</div>
							<div>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; void print()
							</div>
							<div>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; {
							</div>
							<div>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; cout&lt;&lt;&quot;(&quot;&lt;&lt;_x&lt;&lt;&quot;,&quot;&lt;&lt;_y&lt;&lt;&quot;)&quot;&lt;&lt;endl;
							</div>
							<div>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; }
							</div>
							<div>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; <span style="font-size: 12pt; color: #ffff00; background-color: rgb(153, 51, 102);">&nbsp; //友元类</span>
							</div>
							<div>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;<span style="color: #ff0000"><strong> &nbsp; &nbsp; friend class line; </strong></span>&nbsp; &nbsp; <span style="color: #0000ff">&nbsp; &nbsp; &nbsp; //friend line; 也可以</span>
							</div>
							<div>};
							</div>
						</td>
						<td>
							<div>
								<div>float line::dis(const point &amp;a1,const point &amp;a2)
								</div>
								<div>{
								</div>
								<div>&nbsp; &nbsp; &nbsp; &nbsp; return sqrt((a1._x-a2._x)*(a1._x-a2._x)+
								</div>
								<div>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; (a1._y-a2._y)*(a1._y-a2._y));
								</div>
								<div>}
								</div>
								<div>void line::set(point &amp;p1,int x,int y)
								</div>
								<div>{
								</div>
								<div>&nbsp; &nbsp; &nbsp; &nbsp; p1._x=x;
								</div>
								<div>&nbsp; &nbsp; &nbsp; &nbsp; p1._y=y;
								</div>
								<div>}
								</div>
								<div><br />
								</div>
							</div>
							<div>int main()
							</div>
							<div>{
							</div>
							<div>&nbsp; &nbsp; &nbsp; &nbsp; point a1(1,2);
							</div>
							<div>&nbsp; &nbsp; &nbsp; &nbsp; point a2(4,6);
							</div>
							<div>&nbsp; &nbsp; &nbsp; &nbsp; cout&lt;&lt;&quot;a1 &quot;;
							</div>
							<div>&nbsp; &nbsp; &nbsp; &nbsp; a1.print();
							</div>
							<div>&nbsp; &nbsp; &nbsp; &nbsp; line aa;
							</div>
							<div>&nbsp; &nbsp; &nbsp; &nbsp;<span style="color: #ff0000"><strong> cout&lt;&lt;&quot;dis=&quot;&lt;&lt;aa.dis(a1,a2)&lt;&lt;endl;</strong></span>
							</div>
							<div>&nbsp; &nbsp; &nbsp; &nbsp; cout&lt;&lt;&quot;重新设置a1的值：&quot;&lt;&lt;endl;
							</div>
							<div>&nbsp; &nbsp; &nbsp; &nbsp;<span style="color: #ff0000"><strong> aa.set(a1,3,4);</strong></span>
							</div>
							<div>&nbsp; &nbsp; &nbsp; &nbsp; cout&lt;&lt;&quot;a1 &quot;;
							</div>
							<div>&nbsp; &nbsp; &nbsp; &nbsp; a1.print();
							</div>
							<div>&nbsp; &nbsp; &nbsp; &nbsp; return 0;
							</div>
							<div>}
							</div>
							<div><img src="data:image/png;base64,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" />
							</div>
						</td>
					</tr>
				</tbody>
			</table></span>
		</div>
		<div><span style="font-size: medium;"><br /></span>
		</div>
		<div><span style="font-size: 12pt"><br /></span>
		</div>
		<div><span style="font-size: medium;"><br /></span>
		</div>
		<div><span style="font-size: medium;"><br /></span>
		</div>
		<div><span style="font-size: 18pt"><strong>友元是否破坏了封装性：</strong></span>
		</div>
		<div><span style="font-size: medium;">
			<div><br />
			</div>
			<div>&nbsp; &nbsp; &nbsp;不可否认，友元在一定程度上将类的私有成员暴露出来，<span style="color: #ff0000">破坏了信息隐藏机制</span>，似乎是种“副作用很大的药”，但俗话说“良药苦口”，好工具总是要付出点代价的，拿把锋利的刀砍瓜切菜，总是要注意不要割到手指的。
			</div>
			<div><span style="color: #ff0000"><strong>&nbsp; &nbsp; &nbsp;但是</strong></span>友元的存在，使得类的接口扩展更为灵活，使用<span style="color: #ff0000">友元进行运算符重载</span>从概念上也更容易理解一些，而且，C++规则已经极力地将友元的使用限制在了一定范围内，<span style="color: #ff0000"><u>它是单向的、不具备传递性、不能被继承</u></span>，所以，<span style="color: #ff0000">应尽力合理使用友元</span>。
			</div>
			<div><br />
			</div></span>
		</div>
		<div><span style="font-size: medium;"><br /></span>
		</div>
		<div><span style="font-size: 12pt"><br /></span>
		</div>
		<div>
		</div>
	</body>
</html>
