% 原始数据点
xdata = [0,1,2,3,4]'; % x值
ydata = [36.3,35.9,35.6,35.3,35.0]'; % y值

% 使用polyfit进行线性最小二乘法拟合（一次多项式）
p = polyfit(xdata, ydata, 1);

% 提取拟合直线的斜率和截距
slope = p(1);
intercept = p(2);

% 计算拟合直线在xdata对应点的y值
yfit = polyval(p, xdata);

% 绘制原始数据点和拟合直线
figure; % 创建一个新的图形窗口

% 使用较小的散点标记大小（例如，'.' 表示小点）来绘制原始数据点
plot(xdata, ydata, '.', 'MarkerSize', 15); % 绘制原始数据点，使用较小的点标记
hold on; % 保持当前图形，以便在同一图上绘制拟合直线
plot(xdata, yfit, 'r-', 'LineWidth', 1.5); % 绘制拟合直线，使用较细的线宽

% 添加轴标签和标题
xlabel('x'); % x轴标签
ylabel('y'); % y轴标签
title('Least Squares Linear Fit'); % 图形标题

% 添加图例
legend('Data', 'Fit', 'Location', 'NorthWest'); % 图例位置设置在图的西北角

% 显示网格线
grid on;

% 计算R^2值（决定系数）
SSres = sum((ydata - yfit).^2); % 残差平方和
SStot = sum((ydata - mean(ydata)).^2); % 总平方和
R2 = 1 - (SSres / SStot); % R^2值

% 格式化拟合直线的方程字符串，保留到小数点后8位
equationStr = sprintf('y = %.8fx + %.8f', slope, intercept);

% 格式化R^2值字符串，保留到小数点后8位
R2Str = sprintf('R^2 = %.8f', R2);

% 获取当前坐标轴的限制
xlim_val = xlim;
ylim_val = ylim;

% 在图上添加拟合直线的方程
text(xlim_val(1) + 0.05*(xlim_val(2)-xlim_val(1)), ...
     ylim_val(2) - 0.05*(ylim_val(2)-ylim_val(1)), ...
     equationStr, 'FontSize', 10);

% 在图上添加R^2值
text(xlim_val(1) + 0.05*(xlim_val(2)-xlim_val(1)), ...
     ylim_val(2) - 0.1*(ylim_val(2)-ylim_val(1)), ...
     R2Str, 'FontSize', 10);
