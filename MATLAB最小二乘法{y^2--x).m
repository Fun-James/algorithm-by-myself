% 原始数据点  
xdata = [10,20,25,30,35,40]'; % x值  
ydata = [5.917,7.666,8.461,9.094,9.711,10.302]'; % y值  
  
% 使用polyfit进行线性最小二乘法拟合（一次多项式）  
p = polyfit(xdata, ydata.^2, 1);  
  
% 提取拟合直线的斜率和截距  
slope = p(1);  
intercept = p(2);  
  
% 计算拟合直线在xdata对应点的y值  
yfit = polyval(p, xdata);  
  
% 绘制原始数据点和拟合直线  
figure; % 创建一个新的图形窗口  
  
% 使用较小的散点标记大小（例如，'.' 表示小点）来绘制原始数据点  
plot(xdata, ydata.^2, '.', 'MarkerSize', 15); % 绘制原始数据点，使用较小的点标记  
hold on; % 保持当前图形，以便在同一图上绘制拟合直线  
plot(xdata, yfit, 'r-', 'LineWidth', 1.5); % 绘制拟合直线，使用较细的线宽  
  
% 添加轴标签和标题  
xlabel('k'); % x轴标签  
ylabel('l^2'); % y轴标签  
title('Least Squares Linear Fit'); % 图形标题  
  
% 添加图例  
legend('Data', 'Fit', 'Location', 'NorthWest'); % 图例位置设置在图的西北角  
  
% 显示网格线  
grid on;  
  
% 计算R^2值（决定系数）  
SSres = sum((ydata.^2 - yfit).^2); % 残差平方和  
SStot = sum((ydata.^2 - mean(ydata.^2)).^2); % 总平方和  
R2 = 1 - (SSres / SStot); % R^2值  
  
% 格式化拟合直线的方程字符串，保留到小数点后8位  
equationStr = sprintf('y = %.8fx + %.8f', slope, intercept);  
  
% 格式化R^2值字符串，保留到小数点后8位  
R2Str = sprintf('R^2 = %.8f', R2);  
  
% 在图上添加拟合直线的方程  
text(min(xdata), max(yfit)-max(yfit)*0.05, equationStr, ...  
    'HorizontalAlignment', 'left', 'VerticalAlignment', 'middle');  
  
% 在图上添加R^2值  
text(min(xdata), max(yfit)-max(yfit)*0.1, R2Str, ...  
    'HorizontalAlignment', 'left', 'VerticalAlignment', 'middle');