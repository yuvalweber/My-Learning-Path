resource "aws_s3_bucket" "staticWeb" {
  bucket = var.web_bucket_name
}

resource "aws_s3_bucket_acl" "staticWeb" {
  bucket = aws_s3_bucket.staticWeb.id
  acl = "public-read"
}

data "aws_iam_policy_document" "allowPublicRead" {
  statement {
    principals {
      type = "*"
      identifiers = ["*"]
    }

    actions = [
      "s3:GetObject"
    ]

    resources = [
      "${aws_s3_bucket.staticWeb.arn}/*",
    ]
  }
}

resource "aws_s3_bucket_policy" "staticWeb" {
  bucket = aws_s3_bucket.staticWeb.id
  policy = data.aws_iam_policy_document.allowPublicRead.json
}

resource "aws_s3_bucket_website_configuration" "staticWeb" {
  bucket = aws_s3_bucket.staticWeb.id

  index_document {
    suffix = "index.html"
  }

  error_document {
    key = "error.html"
  }
}

resource "aws_s3_object" "staticWebFiles" {
  for_each = fileset("demo-app/", "**")
  bucket = aws_s3_bucket.staticWeb.id
  key = each.value
  content_type = var.content_types["${element(split(".",each.value),length(split(".",each.value)) -1)}"]
  source = "demo-app/${each.value}"
  etag = filemd5("demo-app/${each.value}")
}

resource "aws_cloudfront_distribution" "staticWeb" {
  origin {
    domain_name = "${aws_s3_bucket.staticWeb.bucket_regional_domain_name}"
    origin_id   = "${aws_s3_bucket.staticWeb.bucket_regional_domain_name}"
  }

  price_class = "PriceClass_All"
  enabled             = true
  is_ipv6_enabled     = true

  default_cache_behavior {
    allowed_methods  = ["GET", "HEAD"]
    cached_methods   = ["GET", "HEAD"]
    target_origin_id = "${aws_s3_bucket.staticWeb.bucket_regional_domain_name}"
    compress = true 
    viewer_protocol_policy = "allow-all"
  }

  restrictions {
    geo_restriction {
      restriction_type = "none"
    }
  }

  viewer_certificate {
    cloudfront_default_certificate = true
  }

  tags = {
    Environment = "production"
  }
}