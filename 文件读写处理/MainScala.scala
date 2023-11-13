package cn.ityege

import java.nio.file.{Files, Paths}
import scala.io.{BufferedSource, Source}

object MainScala {
  def main(args: Array[String]): Unit = {
    val source: BufferedSource = Source fromFile("abc.txt", "UTF-8")
    val ints: Iterator[Int] = source.getLines().flatMap(_.split(",").map(_.trim.toInt))
    import scala.collection.JavaConverters._
    Files write(Paths.get("abc_new_scala.txt"), ints.map(_.toString).toList.asJava)
    ints.foreach(println)
  }

}
