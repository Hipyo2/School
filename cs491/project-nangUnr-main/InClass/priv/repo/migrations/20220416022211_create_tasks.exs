defmodule InClass.Repo.Migrations.CreateTasks do
  use Ecto.Migration

  def change do
    create table(:tasks) do
      add :name, :string
      add :description, :string
      add :generalarea_id, references(:generalareas, on_delete: :nothing)

      timestamps()
    end

    create index(:tasks, [:generalarea_id])
  end
end
