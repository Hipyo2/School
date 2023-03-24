defmodule InClass.Repo.Migrations.CreateAssignments do
  use Ecto.Migration

  def change do
    create table(:assignments) do
      add :name, :string
      add :due_date, :string
      add :status_id, references(:statuses, on_delete: :nothing)
      add :developer_id, references(:developers, on_delete: :nothing)
      add :task_id, references(:tasks, on_delete: :nothing)

      timestamps()
    end

    create index(:assignments, [:status_id])
    create index(:assignments, [:developer_id])
    create index(:assignments, [:task_id])
  end
end
