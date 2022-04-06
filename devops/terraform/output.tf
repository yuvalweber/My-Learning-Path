output "dir_perms" {
  value       = local_file.example_file.directory_permission
  description = "output the directory permissions"
}