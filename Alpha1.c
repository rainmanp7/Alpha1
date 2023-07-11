//My attempt at a linux kernal Congestion Control with
// Alpha1 being Congestion Control
// Alpah2 if this is switch called then Packet Compression
// Using a sliding scale is implemented as long as CPU is under 95%
// If you can implement this code so it's called by sysctl that would be great.
// I wrote this code so that I can actually use it or for the
// benefit others that would like such things.
//rainmanp7 aka Chris Brown 07/10/2023 8:59pm

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct SlidingScaleWindow {
int size;
int *data;
int index;
};
void init_sliding_scale_window(struct SlidingScaleWindow *window, int
size) {
window->size = size;
window->data = malloc(sizeof(int) * size);
window->index = 0;
}
void add_data_to_sliding_scale_window(struct SlidingScaleWindow *window,
int data) {
window->data[window->index] = data;
window->index = (window->index + 1) % window->size;
}
float get_average_compression_ratio(struct SlidingScaleWindow *window) {
int i;
float sum = 0;
for (i = 0; i < window->size; i++) {
sum += window->data[i];
}
return sum / window->size;
}
void adjust_congestion_window(struct CongestionControl *cc, int
packet_loss) {
int i;
for (i = 0; i < cc->num_connections; i++) {
if (packet_loss > 0) {
cc->bottlenecks[i] = math.floor(cc->bottlenecks[i] / 2);
} else {
cc->bottlenecks[i] = math.ceil(cc->bottlenecks[i] * 1.1);
}
}
// If the smallest bottleneck is less than 0.8, then enable packet
compression.
float smallest_bottleneck = cc->bottlenecks[0];
for (i = 1; i < cc->num_connections; i++) {
if (cc->bottlenecks[i] < smallest_bottleneck) {
smallest_bottleneck = cc->bottlenecks[i];
}
}
bool packet_compression_enabled = false;
if (smallest_bottleneck < 0.8) {
packet_compression_enabled = true;
}
// If the user calls the alpha2 function, then packet compression will
also be performed.
char *function_name = "alpha1";
if (strcmp(function_name, "alpha2") == 0) {
packet_compression_enabled = true;
}
// If the CPU is at 95% for 3 seconds, then disable packet
compression.
int cpu_usage = 95;
int counter = 0;
while (counter < 3) {
if (cpu_usage > 95) {
packet_compression_enabled = false;
} else {
packet_compression_enabled = true;
}
counter++;
}
// Compress the data using the adjusted compression ratio.
if (packet_compression_enabled) {
// ...
}
}
int main() {
struct SlidingScaleWindow window;
init_sliding_scale_window(&window, 10);
// Add some data to the sliding scale window.
add_data_to_sliding_scale_window(&window, 1);
add_data_to_sliding_scale_window(&window, 2);
add_data_to_sliding_scale_window(&window, 3);
add_data_to_sliding_scale_window(&window, 4);
add_data_to_sliding_scale_window(&window, 5);
// Get the average compression ratio.
float average_compression_ratio =
get_average_compression_ratio(&window);
printf("Average compression ratio: %f\n", average_compression_ratio);
// If the speed slows down, adjust to not so high of a compression
ratio.
if (average_compression_ratio > 0.8) {
// Reduce the compression ratio.
average_compression_ratio = 0.6;
} else {
// Increase the compression ratio.
average_compression_ratio = 0.9;
}
