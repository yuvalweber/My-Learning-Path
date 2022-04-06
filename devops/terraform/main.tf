resource "local_sensitive_file" "example_secret_file" {
  filename = var.filename["first"]
  content  = "${random_password.generated_pass.result}"

  lifecycle {
    prevent_destroy = true
  }
}

resource "random_password" "generated_pass" {
  lower   = true
  length  = var.length[2]
  special = false
  lifecycle {
    create_before_destroy = true
  }
}

resource "local_file" "example_file" {
  filename = var.filename["second"]
  content  = var.content
  depends_on = [
    local_sensitive_file.example_secret_file
  ]

  lifecycle {
    ignore_changes = [
      filename,
      content
    ]
  }
}

data "local_file" "example_data_file" {
  filename = "/root/example3.txt"
}

resource "local_file" "example_data_usage" {
  filename = "/root/example4.txt"
  content = "${data.local_file.example_data_file.content}" 
}

# terraform for_each only works with map or set 
resource "local_file" "loop_files_example" {
  filename = each.value
  content = "example content"
  for_each = var.example_set
}

resource "local_file" "loop_files_toset_example" {
  filename = each.value
  content = "example content"
  for_each = toset(var.random_string_files)
}

resource "random_uuid" "loop_random_uuid" {
  count = 3
}

resource "local_file" "loop_files_count_example" {
  filename = var.random_string_files_count[count.index]
  content = "example content"
  count = 3
}