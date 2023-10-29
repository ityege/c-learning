# 第1章 ffmpeg简介

ffmpeg:FFmpeg既是一款音视频编解码工具，同时也是一组音视频编解码开发套件，作为编解码开发套件，它为开发者提供了丰富的音视频处理的调用接口。

AVFilter使用案例:

~~~shell
./ffmpeg -i INPUT -vf "split [main][tmp]; [tmp] crop=iw:ih/2:0:0, vflip [flip]; [main][flip] overlay=0:H/2" OUTPUT
~~~

ffmpeg使用案例:

~~~shell
./ffmpeg -i input.mp4 output.avi
~~~

~~~shell
./ffmpeg -i input.mp4 -f avi output.dat
~~~

ffprobe使用案例:

~~~shell
./ffprobe -show_streams output.mp4
~~~

# 第2章 ffmpeg工具使用基础

~~~shell
Print help / information / capabilities:
-L                  show license // 显示许可信息 
-h topic            show help // 显示帮助信息
-? topic            show help // 显示帮助信息
-help topic         show help // 显示帮助信息
--help topic        show help // 显示帮助信息
-version            show version // 显示版本        
-buildconf          show build configuration // 显示编译配置
-formats            show available formats // 显示可用格式 , 其等价于 muxers + demuxers 组合 
-muxers             show available muxers // 显示可用的复用器
-demuxers           show available demuxers // 显示可用的解复用器
-devices            show available devices // 显示可用设备
-codecs             show available codecs // 显示可用的编解码器 , 其等价于 encoders + decoders 组合
-decoders           show available decoders // 显示可用的解码器
-encoders           show available encoders // 显示可用的编码器
-bsfs               show available bit stream filters // 显示可用的比特流 filters 过滤器 
-protocols          show available protocols // 显示可用协议 , 如 rtmp , rtsp 等 ; 
-filters            show available filters // 显示可用的过滤器 , 可用于 : 改变播放速度 , 加水印 , 加 Logo 
-pix_fmts           show available pixel formats // 显示可用的像素格式
-layouts            show standard channel layouts // 显示标准声道名称 
-sample_fmts        show available audio sample formats // 显示可用的音频采样格式 
-colors             show available color names // 显示可用的颜色名称 
-sources device     list sources of the input device // 列出输入设备来源 
-sinks device       list sinks of the output device // 列出输出设备接收器
-hwaccels           show available HW acceleration methods // 显示可用的硬件加速方法
~~~

~~~shell
查看FLV封装器的参数支持（ffmpeg -h muxer=flv）
~~~

~~~shell
查看flv解封装器的参数支持（ffmpeg -h demuxer=flv）
~~~

~~~shell
查看H.264（AVC）的编码参数支持（ffmpeg -h encoder=h264）
~~~

~~~shell
查看H.264（AVC）的解码参数支持（ffmpeg -h decoder=h264）
~~~

~~~shell
查看colorkey滤镜的参数支持（ffmpeg -h filter=colorkey）
~~~

ffprobe常用命令:

~~~shell
ffprobe -show_packets input.flv
~~~

~~~shell
ffprobe -show_data -show_packets input.flv
~~~

~~~shell
ffprobe -show_format output.mp4
~~~

~~~shell
ffprobe -show_frames input.flv
~~~

~~~shell
ffprobe -of xml -show_streams input.flv
~~~

~~~shell
ffprobe -of ini -show_streams input.flv
~~~

~~~shell
ffprobe -of flat -show_streams input.flv
~~~

~~~shell
ffprobe -of json -show_packets input.flv
~~~

~~~shell
ffprobe -of csv -show_packets input.flv
~~~

~~~shell
ffprobe -show_frames -select_streams v -of xml input.mp4
~~~

ffplay常用命令:

~~~shell
ffplay -ss 30 -t 10 input.mp4
~~~

~~~shell
ffplay -window_title "Hello World, This is a sample" output.mp4
~~~

~~~shell
#这个没打开
ffplay -window_title "播放测试"  rtmp://up.v.test.com/live/stream
~~~

~~~shell
time ffplay -window_title "Hello World" -ss 20 -t 10 -autoexit output.mp4
~~~

~~~shell
ffplay -vcodec h264 output.mp4
~~~

~~~shell
#没有这个文件
ffplay -vst 4 -ast 5 ~/Movies/movie/ChinaTV-11.ts
~~~

播放视频指定字幕

~~~shell
ffplay -window_title "Test Movie" -vf "subtitles=input.srt" output.mp4
~~~

~~~shell
ffplay -showmode 1 output.mp3
~~~

~~~shell
#报错
ffplay -debug vis_mb_type -window_title "show vis_mb_type" -ss 20 -t 10 -autoexit output.mp4
~~~

~~~shell
#报错
ffplay -vismv pf output.mp4
~~~

~~~shell
ffplay -flags2 +export_mvs -ss 40 output.mp4 -vf codecview=mv=pf+bf+bb
~~~

# 第3章 ffmpeg转封装

## (1)视频文件转MP4格式

mp4格式解码器:

~~~shell
ffmpeg -h demuxer=mp4
~~~

faststart参数使用案例:

~~~shell
./ffmpeg -i input.flv -c copy -f mp4 output.mp4
~~~

~~~shell
#moov移动到了mdat前面
./ffmpeg -i input.flv -c copy -f mp4 -movflags faststart output.mp4
~~~

dash参数使用案例:

~~~shell
./ffmpeg -i input.flv -c copy -f mp4 -movflags dash output.mp4
~~~

isml参数使用案例:

~~~shell
./ffmpeg -re -i input.mp4 -c copy -movflags isml+frag_keyframe -f ismv Stream
~~~

## (2)视频文件转FLV

~~~shell
ffmpeg -i input_ac3.mp4 -c copy -f flv output.flv
~~~

FLV容器中并没有支持AC3音频编码,为了解决这类问题，可以进行转码，将音频从AC3转换为AAC或者MP3这类FLV标准支持的音频即可：

~~~shell
./ffmpeg -i input_ac3.mp4 -vcodec copy -acodec aac -f flv output.flv
~~~

FFmpeg生成带关键索引的FLV

~~~shell
ffmpeg -i input.mp4 -c copy -f flv -flvflags add_keyframe_index output.flv
~~~

使用ffprobe解析FLV文件，并且其还能够将关键帧索引的相关信息打印出来：

~~~shell
ffprobe -v trace -i output.flv
~~~

## (3)视频文件转M3U8

FFmpeg转HLS举例:

~~~shell
./ffmpeg -re -i input.mp4 -c copy -f hls -bsf:v h264_mp4toannexb output.m3u8
~~~

1.start_number参数

~~~shell
./ffmpeg -re -i input.mp4 -c copy -f hls -bsf:v h264_mp4toannexb -start_number 300 output.m3u8
~~~

2.hls_time参数

~~~shell
./ffmpeg -re -i input.mp4 -c copy -f hls -bsf:v h264_mp4toannexb -hls_time 10 output.m3u8
~~~

3.hls_list_size参数

~~~shell
./ffmpeg -re -i input.mp4 -c copy -f hls -bsf:v h264_mp4toannexb -hls_list_size 3 output.m3u8
~~~

4.hls_wrap参数

~~~shell
#参数报错
./ffmpeg -re -i input.mp4 -c copy -f hls -bsf:v h264_mp4toannexb -hls_wrap 3 output.m3u8
~~~

5.hls_base_url参数

~~~shell
#ts文件还是在当前文件夹产生,但是无法播放,因为url是一个网络地址
./ffmpeg -re -i input.mp4 -c copy -f hls -hls_base_url http://192.168.0.1/live/ -bsf:v h264_mp4toannexb output.m3u8
~~~

6.hls_segment_filename参数

~~~shell
#指定产生ts文件名
./ffmpeg -re -i input.mp4 -c copy -f hls -hls_segment_filename test_output-%d.ts -bsf:v h264_mp4toannexb output.m3u8
~~~

7.hls_flags参数

delete_segments子参数

~~~shell
#使用delete_segments参数用于删除已经不在M3U8列表中的旧文件，这里需要注意的是，FFmpeg删除切片时会将hls_list_size大小的2倍作为删除的依据
./ffmpeg -re -i input.mp4 -c copy -f hls -hls_flags delete_segments -hls_list_size 4 -bsf:v h264_mp4toannexb output.m3u8
#会删除ts文件
~~~

round_durations子参数

~~~shell
#长度为整数
./ffmpeg -re -i input.mp4 -c copy -f hls -hls_flags round_durations -bsf:v h264_mp4toannexb output.m3u8
~~~

discont_start子参数

~~~shell
#输出的M3U8在第一片TS信息的前面有一个EXT-X-DISCONTINUTY的标签，这个标签常用于在切片不连续时作特别声明用。
./ffmpeg -re -i input.mp4 -c copy -f hls -hls_flags discont_start -bsf:v h264_mp4toannexb output.m3u8
~~~

omit_endlist子参数

~~~shell
#omit_endlist子参数在生成M3U8结束的时候若不在文件末尾则不追加endlist标签，因为在常规的生成M3U8文件结束时，FFmpeg会默认写入endlist标签，使用这个参数可以控制在M3U8结束时不写入endlist标签
./ffmpeg -re -i input.mp4 -c copy -f hls -hls_flags omit_endlist -bsf:v h264_mp4toannexb output.m3u8
~~~

split_by_time子参数

~~~shell
#没懂
./ffmpeg -re -i input.ts -c copy -f hls -hls_time 2 -hls_flags split_by_time output.m3u8
~~~

8.use_localtime参数

~~~shell
#会报错
./ffmpeg -re -i input.mp4 -c copy -f hls -use_localtime 1 -bsf:v h264_mp4toannexb output.m3u8
~~~

9.method参数

~~~shell
#没懂
./ffmpeg -i input.mp4 -c copy -f hls -hls_time 3 -hls_list_size 0 -method PUT -t 30 http://127.0.0.1/test/output_test.m3u8
~~~

## (4)视频文件切片

FFmpeg切片segment举例:

1.segment_format指定切片文件的格式

~~~shell
./ffmpeg -re -i input.mp4 -c copy -f segment -segment_format mp4 test_output-%d.mp4
~~~

2.segment_list与segment_list_type指定切片索引列表

生成ffconcat格式索引文件

~~~shell
./ffmpeg -re -i input.mp4 -c copy -f segment -segment_format mp4 -segment_list_type ffconcat -segment_list output.lst test_output-%d.mp4
~~~

生成FLAT格式索引文件

~~~shell
./ffmpeg -re -i input.mp4 -c copy -f segment -segment_format mp4 -segment_list_type flat -segment_list filelist.txt test_output-%d.mp4
~~~

生成CSV格式索引文件

~~~shell
./ffmpeg -re -i input.mp4 -c copy -f segment -segment_format mp4 -segment_list_type csv -segment_list filelist.csv test_output-%d.mp4
~~~

生成M3U8格式索引文件

~~~shell
./ffmpeg -re -i input.mp4 -c copy -f segment -segment_format mp4 -segment_list_type m3u8 -segment_list output.m3u8 test_output-%d.mp4
~~~

3.reset_timestamps使切片时间戳归0

~~~shell
./ffmpeg -re -i input.mp4 -c copy -f segment -segment_format mp4 -reset_timestamps 1 test_output-%d.mp4
~~~

~~~shell
ffprobe -v quiet -show_packets -select_streams v test_output-0.mp4 2> x|grep pts_time | tail -n 3

pts_time=3.680000
pts_time=3.800000
pts_time=3.760000
~~~

~~~shell
ffprobe -v quiet -show_packets -select_streams v test_output-1.mp4 2> x|grep pts_time | head -n 3

pts_time=0.000000
pts_time=0.080000
pts_time=0.040000
~~~

4.segment_times按照时间点剪切

~~~shell
./ffmpeg -re -i input.mp4 -c copy -f segment -segment_format mp4 -segment_times 3,9,12 test_output-%d.mp4
~~~

FFmpeg使用ss与t参数进行切片:

1.使用ss指定剪切开头部分

~~~shell
./ffmpeg -ss 10 -i input.mp4 -c copy output.ts
~~~

~~~shell
ffprobe -v quiet -show_format input.mp4 |grep duration; ffprobe -v quiet -show_format output.ts |grep duration

duration=10.006000
duration=2.698667
~~~

2.使用t指定视频总长度

~~~shell
./ffmpeg -i input.mp4 -c copy -t 10 -copyts output.mp4
~~~

~~~shell
ffprobe -v quiet -show_format input.mp4 |grep start_time; ffprobe -v quiet -show_format output.ts |grep start_time

start_time=0.000000
start_time=0.000000
ffprobe -v quiet -show_format input.mp4 |grep duration; ffprobe -v quiet -show_format output.ts |grep duration

duration=10.006000
duration=3.698667
~~~

3.使用output_ts_offset指定输出start_time

~~~shell
./ffmpeg -i input.mp4 -c copy -t 10 -output_ts_offset 120 output.mp4
~~~

## (5)音视频文件音视频流抽取

FFmpeg抽取音视频文件中的AAC音频流

~~~shell
./ffmpeg -i input.mp4 -vn -acodec copy output.aac
~~~

FFmpeg抽取音视频文件中的H.264视频流

~~~shell
./ffmpeg -i input.mp4 -vcodec copy -an output.h264
~~~

FFmpeg抽取音视频文件中的H.265数据

~~~shell
#报错
./ffmpeg -i input.mp4 -vcodec copy -an -bsf hevc_mp4toannexb -f hevc output.hevc
~~~

# 第四章 ffmpeg转码

## (1)ffmpeg软解码H.264与H.265

~~~shell
ffmpeg -h encoder=libx264
~~~

H.264编码举例:

1.编码器预设参数设置preset

~~~shell
./ffmpeg -i input.mp4 -vcodec libx264 -preset ultrafast -b:v 2000k output.mp4
~~~

2.H.264编码优化参数tune

3.H.264的profile与level设置

~~~shell
ffmpeg -i input.mp4 -vcodec libx264 -profile:v baseline -level 3.1 -s 352x288 -an -y -t 10 output_baseline.ts
ffmpeg -i input.mp4 -vcodec libx264 -profile:v high -level 3.1 -s 352x288 -an -y -t 10 output_high.ts




ffprobe -v quiet -show_frames -select_streams v output_baseline.ts |grep "pict_type=B"|wc -l
0
ffprobe -v quiet -show_frames -select_streams v output_high.ts |grep "pict_type=B"|wc -l
140
~~~

4.控制场景切换关键帧插入参数sc_threshold

~~~shell
./ffmpeg -i input.mp4 -c:v libx264 -g 50 -t 60 output.mp4
~~~

5.设置x264内部参数x264opts

~~~shell
./ffmpeg -i input.mp4 -c:v libx264 -x264opts "bframes=0" -g 50 -sc_threshold 0  output.mp4

./ffmpeg -i input.mp4 -c:v libx264 -x264opts "bframes=3:b-adapt=0" -g 50 -sc_threshold 0 output.mp4
~~~

6.CBR恒定码率设置参数nal-hrd

~~~shell
./ffmpeg -i input.mp4 -c:v libx264 -x264opts "bframes=10:b-adapt=0"  -b:v 1000k -maxrate 1000k -minrate 1000k -bufsize 50k -nal-hrd cbr -g 50 -sc_threshold 0 output.ts
~~~



## (2)ffmpeg硬解码

Nvidia GPU硬编解码

~~~shell
./ffmpeg -hwaccel cuvid -vcodec h264_cuvid -i input.mp4 -vf scale_npp=1920:1080 -vcodec h264_nvenc -acodec copy -f mp4 -y output.mp4
~~~

Intel QSV硬解码

~~~shell
./ffmpeg -hide_banner -codecs|grep h264
~~~

~~~shell
./ffmpeg -i 10M1080P.mp4 -pix_fmt nv12 -vcodec h264_qsv -an -y output.mp4
~~~

~~~shell
./ffmpeg -hide_banner -y -hwaccel qsv -i 10M1080P.mp4 -an -c:v hevc_qsv -load_plugin hevc_hw -b:v 5M -maxrate 5M out.mp4
~~~

树莓派硬解码

~~~shell
./ffmpeg -i input.mp4 -vcodec h264_omx -b:v 500k -acodec copy -y output.mp4
~~~

OS X系统硬编解码

~~~shell
./ffmpeg -vcodec h264_vda -i input.mp4 -vcodec h264_videotoolbox -b:v 2000k output.mp4
~~~

## (3) ffmpeg输出MP3

没有这个编码器

~~~shell
ffmpeg -h encoder=libmp3lame
~~~

但是有这个mp3_mf

MP3的编码质量设置

~~~shell
./ffmpeg –i INPUT –acodec libmp3lame OUTPUT.mp3
~~~

~~~shell
./ffmpeg -i input.mp3 -acodec libmp3lame -q:a 8 output.mp3
~~~

~~~shell
./ffmpeg -i input.mp3 -acodec libmp3lame -b:a 64k output.mp3
~~~

平均码率编码参数ABR

~~~shell
./ffmpeg -i input.mp3 –acodec libmp3lame -b:a 64k -abr 1 output.mp3
~~~

## (4) ffmpeg输出AAC

FFmpeg可以支持AAC的三种编码器具体如下。
·aac：FFmpeg本身的AAC编码实现
·libfaac：第三方的AAC编码器
·libfdk_aac：第三方的AAC编码器

FFmpeg中的AAC编码器使用

~~~shell
./ffmpeg -i input.mp4 -c:a aac -b:a 160k output.aac
~~~

~~~shell
./ffmpeg -i input.wav -c:a aac -q:a 2 output.m4a
~~~

FDK AAC第三方的AAC编解码Codec库

1.恒定码率（CBR）模式

~~~shell
./ffmpeg -i input.wav -c:a libfdk_aac -b:a 128k output.m4a
~~~

~~~shell
./ffmpeg -i input.mp4 -c:v copy -c:a libfdk_aac -b:a 384k output.mp4
~~~

2.动态码率（VBR）模式

~~~shell
./ffmpeg -i input.wav -c:a libfdk_aac -vbr 3 output.m4a
~~~

高质量AAC设置

1.HE-AAC音频编码设置

~~~shell
./ffmpeg -i input.wav -c:a libfdk_aac -profile:a aac_he -b:a 64k output.m4a
~~~

2.HEv2-AAC音频编码设置

~~~shell
./ffmpeg -i input.wav -c:a libfdk_aac -profile:a aac_he_v2 -b:a 32k output.m4a
~~~

AAC音频质量对比

~~~txt
AAC-LC的音频编码可以采用libfaac、libfdk_aac、FFmpeg内置AAC三种，其质量顺序排列如下。
·libfdk_aac音频编码质量最优
·FFmpeg内置AAC编码次于libfdk_aac但优于libfaac
·libfaac在FFmpeg内置AAC编码为实验品时是除了libfdk_aac之外的唯一选择
注意：
在新版本的FFmpeg中，libfaac已经被删除。
~~~

# 第五章 ffmpeg流媒体

## (1)ffmpeg发布和录制RTMP流

1.rtmp_app参数

~~~shell
ffmpeg -rtmp_app live -i rtmp://publish.chinaffmpeg.com -c copy -f flv output.flv
~~~

~~~shell
ffmpeg -re -i input.mp4 -c copy -f flv -rtmp_app live rtmp://publish.chinaffmpeg.com
~~~

2.rtmp_playpath参数

~~~shell
ffmpeg -re -i input.mp4 -c copy -f flv -rtmp_app live -rtmp_playpath class rtmp://publish.chinaffmpeg.com
~~~

~~~shell
./ffmpeg -rtmp_app live -rtmp_playpath class -i rtmp://publish.chinaffmpeg.com -c copy -f flv output.flv
~~~

~~~shell
./ffmpeg -i input.mp4 -c copy -f flv rtmp://publish.chinaffmpeg.com/live/class
~~~

~~~shell
./ffmpeg -i rtmp://publish.chinaffmpeg.com/live/class -c copy -f flv output.flv
~~~

3.rtmp_pageurl、rtmp_swfurl、rtmp_tcurl参数

~~~shell
./ffmpeg -rtmp_pageurl "http://www.chinaffmpeg.com" -i rtmp://publish.chinaffmpeg.com/live/class
~~~

## (2)ffmpeg发布和录制RTSP流

1.TCP方式录制RTSP直播流

~~~shell
./ffmpeg -rtsp_transport tcp -i rtsp://47.90.47.25/test.ts -c copy -f mp4 output.mp4
~~~

2.User-Agent设置参数

~~~shell
./ffmpeg -user-agent "ChinaFFmpeg-Player" -i rtsp://input:554/live/1/stream.sdp -c copy -f mp4 -y output.mp4
~~~

## (3)ffmpeg录制HTTP流

1.seekable参数举例

~~~shell
./ffmpeg -ss 300 -seekable 0 -i http://bbs.chinaffmpeg.com/test.ts -c copy output.mp4
~~~

~~~shell
./ffmpeg -ss 30 -seekable 1 -i http://bbs.chinaffmpeg.com/test.ts -c copy -y output.mp4
~~~

2.headers参数举例

~~~shell
./ffmpeg -headers "referer: http://bbs.chinaffmpeg.com/index.html" -i http://play.chinaffmpeg.com/live/class.flv -c copy -f flv -y output.flv
~~~

3.user_agent参数设置

~~~shell
./ffmpeg -user_agent "LiuQi's Player" -i http://bbs.chinaffmpeg.com/1.flv
~~~

拉取HTTP中的流录制FLV

1）拉取FLV直播流录制为FLV:

~~~shell
./ffmpeg -i http://bbs.chinaffmpeg.com/live.flv -c copy -f flv output.flv
~~~

2）拉取TS直播流录制为FLV：

~~~shell
./ffmpeg -i http://bbs.chinaffmpeg.com/live.ts -c copy -f flv output.flv
~~~

3）拉取HLS直播流录制为FLV：

~~~shell
./ffmpeg -i http://bbs.chinaffmpeg.com/live.m3u8 -c copy -f flv output.flv
~~~

## (4)ffmpeg录制和发布UDP/TCP流

1.TCP监听接收流

~~~shell
./ffmpeg -listen 1 -f flv -i tcp://127.0.0.1:1234/live/stream -c copy -f flv output.flv
~~~

2.TCP请求发布流

~~~shell
./ffmpeg -re -i input.mp4 -c copy -f flv tcp://127.0.0.1:1234/live/stream
~~~

3.监听端口超时listen_timeout

~~~shell
time ./ffmpeg -listen_timeout 5000 -listen 1 -f flv -i tcp://127.0.0.1:1234/live/stream -c copy -f flv output.flv
~~~

4.TCP拉流超时参数timeout

~~~shell
time ./ffmpeg -timeout 20000000 -i tcp://192.168.100.179:1935/live/stream -c copy -f flv output.flv
~~~

5.TCP传输buffer大小设置send_buffer_size/recv_buffer_size

~~~shell
./ffmpeg -re -i input.mp4 -c copy -send_buffer_size 265 -f flv tcp://192.168.100.179:1234/live/stream
~~~

6.绑定本地UDP端口localport

~~~shell
./ffmpeg -re -i input.mp4 -c copy -localport 23456 -f flv udp://192.168.100.179:1234/live/stream
~~~

## (5)ffmpeg推多路流

管道方式输出多路流:

~~~shell
./ffmpeg -i input -acodec aac -vcodec libx264 -f flv - | ffmpeg -f mpegts -i - -c copy output1 -c copy output2 -c copy output3
~~~

~~~shell
./ffmpeg -i input.mp4 -vcodec libx264 -acodec aac -f flv - | ffmpeg -f flv -i - -c copy -f flv rtmp://publish.chinaffmpeg.com/live/stream1 -c copy -f flv rtmp://publish.chinaffmpeg.com/live/stream2
~~~

~~~shell
./ffmpeg -i rtmp://publish.chinaffmpeg.com/live/stream1  -i rtmp://publish.chinaffmpeg.com/live/stream2
~~~

tee封装格式输出多路流:

~~~shell
./ffmpeg -re -i input.mp4 -vcodec libx264 -acodec aac -map 0 -f tee "[f=flv]rtmp://publish.chinaffmpeg.com/live/stream1 | [f=flv]rtmp:// publish.chinaffmpeg.com/live/stream2"
~~~

~~~shell
./ffmpeg -i rtmp://publish.chinaffmpeg.com/live/stream1  -i rtmp://publish.chinaffmpeg.com/live/stream2
~~~

tee协议输出多路流

~~~shell
./ffmpeg -re -i input.mp4 -vcodec libx264 -acodec aac -f flv "tee:rtmp://publish.chinaffmpeg.com/live/stream1|rtmp://publish.chinaffmpeg.com/live/stream2"
~~~

## (6)ffmpeg生成HDS流

1.window_size参数控制文件列表大小

~~~shell
./ffmpeg -i input -c copy -f hds -window_size 4 output
~~~

~~~shell
./ffmpeg -i input -c copy -f hds output
~~~

2.extra_window_size参数控制文件个数

~~~shell
./ffmpeg -re -i input.mp4 -c copy -f hds -window_size 4 -extra_window_size 1 output
~~~

~~~shell
./ffmpeg -re -i input.mp4 -c copy -f hds -window_size 4 -extra_window_size 5 output
~~~

3.其他参数

## (7)ffmpeg生成DASH流

1.window_size与extra_window_size参数举例

~~~shell
./ffmpeg -re -i input.mp4 -c:v copy -acodec copy -f dash -window_size 4 -extra_window_size 5 index.mpd
~~~

2.single_file参数举例

~~~shell
./ffmpeg -re -i input.mp4 -c:v copy -acodec copy -f dash -window_size 4 -extra_window_size 5 -single_file 1 index.mpd
~~~

# 第六章 FFmpeg滤镜使用

## (1)FFmpeg滤镜Filter描述格式

输入两个文件，一个视频input.mp4，一个图片logo.png，将logo进行缩放，然后放在视频的左上角:

~~~shell
./ffmpeg -i input.mp4 -i logo.png -filter_complex "[1:v]scale=176:144[logo];[0:v][logo]overlay=x=0:y=0" output.mp4
~~~

## (2)FFmpeg为视频加水印

文字水印

~~~shell
./ffmpeg -i input.mp4 -vf "drawtext=fontsize=100:fontfile=FreeSerif.ttf:text='hello world':x=20:y=20" output.mp4
~~~

~~~shell
./ffmpeg -i input.mp4 -vf "drawtext=fontsize=100:fontfile=FreeSerif.ttf:text='hello world':fontcolor=green" output.mp4
~~~

~~~shell
./ffmpeg -i input.mp4 -vf "drawtext=fontsize=100:fontfile=FreeSerif.ttf:text='hello world':fontcolor=green:box=1:boxcolor=yellow" output.mp4
~~~

~~~shell
./ffmpeg -re -i input.mp4 -vf "drawtext=fontsize=60:fontfile=FreeSerif.ttf:text='%{localtime\:%Y\-%m\-%d %H-%M-%S}':fontcolor=green:box=1:boxcolor=yellow" output.mp4
~~~

~~~shell
./ffmpeg -re -i input.mp4 -vf "drawtext=fontsize=60:fontfile=FreeSerif.ttf:text='test':fontcolor=green:box=1:boxcolor=yellow:enable=lt(mod(t\,3)\,1)" output.mp4
~~~

~~~shell
./ffmpeg -re -i input.mp4 -vf "drawtext=fontsize=50:fontfile=/Library/Fonts/Songti.ttc:text='文字水印测试':fontcolor=green:box=1:boxcolor=yellow" output.mp4
~~~

图片水印:

~~~shell
./ffmpeg -i input.mp4 -vf "movie=logo.png[wm]; [in][wm]overlay=30:10[out]" output.mp4
~~~

~~~shell
./ffmpeg -i input.mp4 -vf "movie=logo.png,colorkey=black:1.0:1.0 [wm]; [in] [wm]overlay=30:10 [out]" output.mp4
~~~

## (3)FFmpeg生成画中画

~~~shell
./ffmpeg -re -i input.mp4 -vf "movie=sub.mp4,scale=480x320[test]; [in][test] overlay [out]" -vcodec libx264 output.flv
~~~

~~~shell
./ffmpeg -re -i input.mp4 -vf "movie=sub.mp4,scale=480x320[test]; [in][test] overlay=x=main_w-480:y=main_h-320 [out]" -vcodec libx264 output.flv
~~~

~~~shell
./ffmpeg -re -i input.mp4 -vf "movie=sub.mp4,scale=480x320[test]; [in][test] overlay=x='if(gte(t,2), -w+(t-2)*20, NAN)':y=0 [out]" -vcodec libx264 output.flv
~~~

## (4)FFmpeg视频多宫格处理

~~~shell
./ffmpeg -re -i input1.mp4 -re -i input2.mp4 -re -i input3.m2t -re -i input4.mp4 -filter_complex "nullsrc=size=640x480 [base]; [0:v] setpts=PTS-STARTPTS, scale=320x240 [upperleft]; [1:v] setpts=PTS-STARTPTS, scale=320x240 [upperright]; [2:v] setpts=PTS-STARTPTS, scale=320x240 [lowerleft]; [3:v] setpts=PTS-STARTPTS, scale=320x240 [lowerright]; [base][upperleft] overlay=shortest=1 [tmp1]; [tmp1][upperright] overlay=shortest=1:x=320 [tmp2]; [tmp2][lowerleft] overlay=shortest=1:y=240 [tmp3]; [tmp3][lowerright] overlay=shortest=1:x=320:y=240" -c:v libx264 output.flv
~~~

## (5)FFmpeg音频流滤镜操作

双声道合并单声道

~~~shell
./ffmpeg -i input.aac -ac 1 output.aac
~~~

双声道提取

~~~shell
./ffmpeg -i input.aac -map_channel 0.0.0 left.aac -map_channel 0.0.1 right.aac
~~~

~~~shell
./ffmpeg -i input.aac -filter_complex "[0:0]pan=1c|c0=c0[left];[0:0]pan=1c|c0=c1[right]" -map "[left]" left.aac -map "[right]" right.aac
~~~

双声道转双音频流

~~~shell
./ffmpeg -i input.aac -filter_complex channelsplit=channel_layout=stereo output.mka
~~~

单声道转双声道

~~~shell
./ffmpeg -i left.aac -ac 2 output.m4a
~~~

~~~shell
./ffmpeg -i left.aac -filter_complex "[0:a][0:a]amerge=inputs=2[aout]" -map "[aout]" output.m4a
~~~

两个音频源合并双声道

~~~shell
./ffmpeg -i left.aac -i right.aac -filter_complex "[0:a][1:a]amerge=inputs=2[aout]" -map "[aout]" output.mka
~~~

多个音频合并为多声道

~~~shell
./ffmpeg -i front_left.wav -i front_right.wav -i front_center.wav -i lfe.wav -i back_left.wav -i back_right.wav -filter_complex "[0:a][1:a][2:a][3:a][4:a][5:a]amerge=inputs=6[aout]" -map "[aout]" output.wav
~~~

## (6)FFmpeg音频音量探测

音频音量获得

~~~Shell
./ffmpeg -i output.wav -filter_complex volumedetect -c:v copy -f null /dev/null
~~~

绘制音频波形

~~~shell
./ffmpeg -i output.wav -filter_complex "showwavespic=s=640x120" -frames:v 1 output.png
~~~

~~~shell
./ffmpeg -i output.wav -filter_complex "showwavespic=s=640x240:split_channels=1" -frames:v 1 output.png
~~~

## (7)FFmpeg为视频加字幕

ASS字幕流写入视频流

~~~shell
./ffmpeg -i input.mp4 -vf ass=t1.ass -f mp4 output.mp4
~~~

ASS字幕流写入封装容器

~~~shell
./ffmpeg -i input.mp4 -i t1.ass -acodec copy -vcodec copy -scodec copy output.mkv
~~~

~~~shell
./ffmpeg -i input.mp4 -i t1.ass -map 0:0 -map 0:1 -map 1:0 -acodec copy -vcodec copy -scodec copy output.mkv
~~~

## (8)FFmpeg视频抠图合并

这个牛逼,绿幕

~~~shell
./ffmpeg -i input.mp4 -i input_green.mp4 -filter_complex "[1:v]chromakey=Green:0.1:0.2[ckout];[0:v][ckout]overlay[out]" -map "[out]" output.mp4
~~~

## (9)FFmpeg3D视频处理

~~~shell
ffplay -vf "stereo3d=sbsl:aybd" input.mp4
~~~

~~~shell
ffplay -vf "stereo3d=sbsl:arbg" input.mp4
~~~

## (10)FFmpeg定时视频截图

vframe参数截取一张图片

~~~shell
./ffmpeg -i input.flv -ss 00:00:7.435 -vframes 1 out.png
~~~

fps滤镜定时获得图片

~~~shell
./ffmpeg -i input.flv -vf fps=1 out%d.png
~~~

~~~shell
./ffmpeg -i input.flv -vf fps=1/60 img%03d.jpg
~~~

~~~shell
./ffmpeg -i input.flv -vf fps=1/600 thumb%04d.bmp
~~~

~~~shell
./ffmpeg -i input.flv -vf "select='eq(pict_type,PICT_TYPE_I)'" -vsync vfr thumb%04d.png
~~~

## (11)FFmpeg生成测试元数据

FFmpeg生成音频测试流

~~~shell
./ffmpeg -re -f lavfi -i abuffer=sample_rate=44100:sample_fmt=s16p:channel_layout=stereo -acodec aac -y output.aac
~~~

~~~shell
./ffmpeg -re -f lavfi "aevalsrc=sin(420*2*PI*t)|cos(430*2*PI*t):c=FC|BC" -acodec aac output.aac
~~~

FFmpeg生成视频测试流

~~~shell
./ffmpeg -re -f lavfi -i testsrc=duration=5.3:size=qcif:rate=25 -vcodec libx264 -r:v 25 output.mp4
~~~

~~~shell
./ffmpeg -re -f lavfi -i testsrc2=duration=5.3:size=qcif:rate=25 -vcodec libx264 -r:v 25 output.mp4
~~~

~~~shell
./ffmpeg -re -f lavfi -i color=c=red@0.2:s=qcif:r=25 -vcodec libx264 -r:v 25 output.mp4
~~~

~~~shell
./ffmpeg -re -f lavfi -i "nullsrc=s=256x256, geq=random(1)*255:128:128" -vcodec libx264 -r:v 25 output.mp4
~~~

## (12)FFmpeg对音视频倍速处理

atempo音频倍速处理

（1）半速处理

~~~shell
./ffmpeg -i input.wav -filter_complex "atempo=tempo=0.5" -acodec aac output.aac
~~~

（2）2倍速处理

~~~shell
./ffmpeg -i input.wav -filter_complex "atempo=tempo=2.0" -acodec aac output.aac
~~~

setpts视频倍速处理

（1）半速处理

~~~shell
./ffmpeg -re -i input.mp4 -filter_complex "setpts=PTS*2" output.mp4
~~~

（2）2倍速处理

~~~shell
./ffmpeg -i input.mp4 -filter_complex "setpts=PTS/2" output.mp4
~~~

# 第七章 FFmpeg采集设备

## (1)FFmpeg中Linux设备操作

Linux下查看设备列表

~~~shell
./ffmpeg –hide_banner –devices
~~~

Linux采集设备fbdev参数说明

~~~shell
./ffmpeg -h demuxer=fbdev
~~~

Linux采集设备fbdev使用举例

~~~shell
./ffmpeg -framerate 30 -f fbdev -i /dev/fb0 output.mp4
~~~

Linux采集设备v4l2参数说明

~~~shell
./ffmpeg -h demuxer=v4l2
~~~

Linux采集设备v4l2使用举例

~~~shell
./ffmpeg -hide_banner -f v4l2 -list_formats all -i /dev/video0
~~~

Linux采集设备x11grab参数说明:

~~~shell
~~~

Linux采集设备x11grab使用举例

（1）桌面录制

~~~shell
./ffmpeg -f x11grab -framerate 25 -video_size 1366x768 -i :0.0 out.mp4
~~~

（2）桌面录制指定起始位置

~~~shell
./ffmpeg -f x11grab -framerate 25 -video_size 352x288 -i :0.0+300,200 out.mp4
~~~

（3）桌面录制带鼠标记录的视频

~~~shell
./ffmpeg -f x11grab -video_size 1366x768 -follow_mouse 1 -i :0.0 out.mp4
~~~

## (2)FFmpeg中OS X设备操作

OS X下查看设备列表

~~~shell
./ffmpeg -devices
~~~

OS X下设备采集举例

~~~shell
./ffmpeg -f avfoundation -list_devices true -i ""
~~~

（1）采集内置摄像头

~~~shell
ffmpeg -f avfoundation -i " FaceTime HD Camera (Built-in)" out.mp4
~~~

（2）采集OS X桌面

~~~shell
ffmpeg -f avfoundation -i "Capture screen 0" –r:v 30 out.mp4
~~~

~~~shell
ffmpeg -f avfoundation -capture_cursor 1 -i "Capture screen 0" -r:v 30 out.mp4
~~~

（3）采集麦克风

~~~shell
ffmpeg -f avfoundation -i "0:0" out.aac
~~~

~~~shell
ffmpeg -f avfoundation -video_device_index 0 -i ":0" out.aac
ffmpeg -f avfoundation -video_device_index 0 -audio_device_index 0 out.aac
~~~

## (3)FFmpeg中Windows设备操作

FFmpeg使用dshow采集音视频设备

（1）使用dshow枚举设备

~~~shell
./ffmpeg.exe -f dshow -list_devices true -i dummy
~~~

（2）使用dshow展示摄像头

~~~shell
ffplay.exe -f dshow -video_size  1280x720  -i video="Integrated Camera"
~~~

（3）将摄像头数据保存为MP4文件

~~~shell
./ffmpeg.exe –f dshow -i video ="Integrated Camera"  -f dshow  -i 
audio="virtual-audio-capturer" out.mp4
~~~

FFmpeg使用vfwcap采集视频设备

（1）使用vfwcap枚举支持采集的设备

~~~shell
./ffmpeg.exe -f vfwcap -i list
~~~

（2）使用vfwcap生成MP4文件

~~~shell
./ffmpeg.exe -f vfwcap -i 0 -r 25 -vcodec libx264 out.mp4
~~~

FFmpeg使用gdigrab采集窗口

（1）使用gdigrab采集整个桌面

~~~shell
./ffmpeg.exe -f gdigrab -framerate 6 -i desktop out.mp4
~~~

（2）使用gdigrab采集某个窗口

~~~shell
./ffmpeg.exe -f gdigrab -framerate 6 -i title=ffmpeg out.mp4
~~~

（3）使用gdigrab录制带偏移量的视频

~~~shell
./ffmpeg.exe -f gdigrab -framerate 6 -offset_x 50 -offset_y 50 -video_size 400x400 -i title=ffmpeg out.mp4
~~~

# 





# 附录:

## ffmpeg编译

1、https://blog.csdn.net/qq_37363702/article/details/123277359

2、在msys中使用linux环境安装成功,见另一个文件（推荐）

## ngnix安装RTMP

~~~shell
apt install gcc
#apt install pcre pcre-devel
#apt install openssl openssl-devel
apt install openssl
apt install wget 
~~~

~~~shell
apt-get install build-essential libpcre3 libpcre3-dev libssl-dev
sudo apt-get install openssl libssl-dev
apt-get install zlib1g-dev
~~~



~~~shell
wget https://nginx.org/download/nginx-1.20.2.tar.gz
~~~

~~~shell
wget https://github.com/arut/nginx-rtmp-module/archive/refs/tags/v1.2.2.tar.gz
~~~

~~~shell
./configure --prefix=/opt/soft/nginx-rtmp/nginx-1.20.2/build --add-module=/opt/soft/ngnix/nginx-rtmp-module-1.2.2
make
make install
~~~

nginx_rtmp.conf

~~~conf
#user  nobody;
worker_processes  1;
#error_log  logs/error.log;
#error_log  logs/error.log  notice;
#error_log  logs/error.log  info;

#pid        logs/nginx.pid;


events {
    worker_connections  1024;
}

rtmp {
    server {
        listen 1935;
        chunk_size 4096;

        # live on
        application rtmp_live {
            live on;
            #hls on; #这个参数把直播服务器改造成实时回放服务器。
            #wait_key on; #对视频切片进行保护，这样就不会产生马赛克了。
            #hls_path ./sbin/html; #切片视频文件存放位置。
            #hls_fragment 10s;     #每个视频切片的时长
            #hls_playlist_length 60s;  #总共可以回看的时间，这里设置的是1分钟。
            #hls_continuous on; #连续模式。
            #hls_cleanup on;    #对多余的切片进行删除。
            #hls_nested on;     #嵌套模式。
        }

        #play videos
        application rtmp_play{
            play ./videos;  #build directory
        }
    }
}
http {
    include       mime.types;
    default_type  application/octet-stream;

    #log_format  main  '$remote_addr - $remote_user [$time_local] "$request" '
    #                  '$status $body_bytes_sent "$http_referer" '
    #                  '"$http_user_agent" "$http_x_forwarded_for"';

    #access_log  logs/access.log  main;

    sendfile        on;
    #tcp_nopush     on;

    #keepalive_timeout  0;
    keepalive_timeout  65;

    #gzip  on;

    server {
        listen       80;
        server_name  localhost;

        #charset koi8-r;

        #access_log  logs/host.access.log  main;

        location / {
            root   html;
            index  index.html index.htm;
        }

        #error_page  404              /404.html;

        # redirect server error pages to the static page /50x.html
        #
        error_page   500 502 503 504  /50x.html;
        location = /50x.html {
            root   html;
        }

        # proxy the PHP scripts to Apache listening on 127.0.0.1:80
        #
        #location ~ \.php$ {
        #    proxy_pass   http://127.0.0.1;
        #}

        # pass the PHP scripts to FastCGI server listening on 127.0.0.1:9000
        #
        #location ~ \.php$ {
        #    root           html;
        #    fastcgi_pass   127.0.0.1:9000;
        #    fastcgi_index  index.php;
        #    fastcgi_param  SCRIPT_FILENAME  /scripts$fastcgi_script_name;
        #    include        fastcgi_params;
        #}

        # deny access to .htaccess files, if Apache's document root
        # concurs with nginx's one
        #
        #location ~ /\.ht {
        #    deny  all;
        #}
    }


    # another virtual host using mix of IP-, name-, and port-based configuration
    #
    #server {
    #    listen       8000;
    #    listen       somename:8080;
    #    server_name  somename  alias  another.alias;

    #    location / {
    #        root   html;
    #        index  index.html index.htm;
    #    }
    #}


    # HTTPS server
    #
    #server {
    #    listen       443 ssl;
    #    server_name  localhost;

    #    ssl_certificate      cert.pem;
    #    ssl_certificate_key  cert.key;

    #    ssl_session_cache    shared:SSL:1m;
    #    ssl_session_timeout  5m;

    #    ssl_ciphers  HIGH:!aNULL:!MD5;
    #    ssl_prefer_server_ciphers  on;

    #    location / {
    #        root   html;
    #        index  index.html index.htm;
    #    }
    #}
}
~~~



~~~shell
/opt/soft/nginx-rtmp/nginx-1.20.2/build/sbin/nginx -c /opt/soft/nginx-rtmp/nginx-1.20.2/build/conf/nginx_rtmp.conf
~~~

推流:

~~~shell
ffmpeg -stream_loop -1 -v verbose -re -i bilibili.mp4  -f flv rtmp://192.168.184.131:1935/rtmp_live/mystream
~~~

播放

~~~shell
rtmp://192.168.184.131:1935/rtmp_live/mystream
~~~

## 录屏

~~~shell
ffmpeg.exe -f gdigrab -framerate 6 -i desktop out.mp4
~~~

