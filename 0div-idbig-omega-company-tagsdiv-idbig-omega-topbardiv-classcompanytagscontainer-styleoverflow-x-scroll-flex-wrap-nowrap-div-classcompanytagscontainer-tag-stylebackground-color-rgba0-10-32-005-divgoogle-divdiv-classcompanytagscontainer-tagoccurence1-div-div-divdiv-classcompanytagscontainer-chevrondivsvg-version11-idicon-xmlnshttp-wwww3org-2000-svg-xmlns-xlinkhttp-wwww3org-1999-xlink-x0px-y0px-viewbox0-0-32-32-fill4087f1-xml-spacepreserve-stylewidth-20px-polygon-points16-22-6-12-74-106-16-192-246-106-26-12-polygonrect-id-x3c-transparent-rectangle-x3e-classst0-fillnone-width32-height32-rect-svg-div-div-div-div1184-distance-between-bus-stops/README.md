<h2><a href="https://leetcode.com/problems/distance-between-bus-stops/"><div id="big-omega-company-tags"><div id="big-omega-topbar"><div class="companyTagsContainer" style="overflow-x: scroll; flex-wrap: nowrap;"><div class="companyTagsContainer--tag" style="background-color: rgba(0, 10, 32, 0.05);"><div>Google</div><div class="companyTagsContainer--tagOccurence">1</div></div></div><div class="companyTagsContainer--chevron"><div><svg version="1.1" id="icon" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" viewBox="0 0 32 32" fill="#4087F1" xml:space="preserve" style="width: 20px;"><polygon points="16,22 6,12 7.4,10.6 16,19.2 24.6,10.6 26,12 "></polygon><rect id="_x3C_Transparent_Rectangle_x3E_" class="st0" fill="none" width="32" height="32"></rect></svg></div></div></div></div>1184. Distance Between Bus Stops</a></h2><h3>Easy</h3><hr><div><p>A bus&nbsp;has <code>n</code> stops numbered from <code>0</code> to <code>n - 1</code> that form&nbsp;a circle. We know the distance between all pairs of neighboring stops where <code>distance[i]</code> is the distance between the stops number&nbsp;<code>i</code> and <code>(i + 1) % n</code>.</p>

<p>The bus goes along both directions&nbsp;i.e. clockwise and counterclockwise.</p>

<p>Return the shortest distance between the given&nbsp;<code>start</code>&nbsp;and <code>destination</code>&nbsp;stops.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2019/09/03/untitled-diagram-1.jpg" style="width: 388px; height: 240px;"></p>

<pre><strong>Input:</strong> distance = [1,2,3,4], start = 0, destination = 1
<strong>Output:</strong> 1
<strong>Explanation:</strong> Distance between 0 and 1 is 1 or 9, minimum is 1.</pre>

<p>&nbsp;</p>

<p><strong class="example">Example 2:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2019/09/03/untitled-diagram-1-1.jpg" style="width: 388px; height: 240px;"></p>

<pre><strong>Input:</strong> distance = [1,2,3,4], start = 0, destination = 2
<strong>Output:</strong> 3
<strong>Explanation:</strong> Distance between 0 and 2 is 3 or 7, minimum is 3.
</pre>

<p>&nbsp;</p>

<p><strong class="example">Example 3:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2019/09/03/untitled-diagram-1-2.jpg" style="width: 388px; height: 240px;"></p>

<pre><strong>Input:</strong> distance = [1,2,3,4], start = 0, destination = 3
<strong>Output:</strong> 4
<strong>Explanation:</strong> Distance between 0 and 3 is 6 or 4, minimum is 4.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n&nbsp;&lt;= 10^4</code></li>
	<li><code>distance.length == n</code></li>
	<li><code>0 &lt;= start, destination &lt; n</code></li>
	<li><code>0 &lt;= distance[i] &lt;= 10^4</code></li>
</ul></div>